import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    return render_template("index.html")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        # submitted via post, lookup the stock symbol by calling the lookup function and display the result
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        # Ensure symbol not empty
        if not symbol:
            return apology("must provide symbol", 400)
        # Ensure shares not empty
        if not shares:
            return apology("must provide shares", 400)

        current_user_id = session["user_id"]
        result = lookup(symbol)
        symbol = result["symbol"]
        name = result["name"]
        current_price = float(result["price"])
        total_price = current_price * float(shares)
        total_cash = db.execute("SELECT cash FROM users WHERE id = ?", current_user_id)
        cash = db.execute("SELECT cash FROM users WHERE id = ?", current_user_id)

        #real valid cash
        valid_cash = cash[0]["cash"]

        if valid_cash < total_price:
            return apology("can not afford", 400)

        if result:
            # Add one or more new tables to finance.db via which to keep track of the purchase.
            db.execute("INSERT INTO buy_histories (symbol, name, shares, price, total) VALUES(?, ?, ?, ?, ?)", symbol, name, shares, current_price, total_price)
            return render_template("index.html", symbol=symbol, name=name, shares=shares, current_price=current_price, total_price=round(total_price, 2), valid_cash=valid_cash, total_cash=total_cash)
        else:
            return apology("invalid symbol", 400)

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        # submitted via post, lookup the stock symbol by calling the lookup function and display the result
        symbol = request.form.get("symbol")

        # Ensure symbol not empty
        if not symbol:
            return apology("must provide symbol", 400)

        result = lookup(symbol)

        if result:
            return render_template(
                "quoted.html", symbol=result["symbol"], price=result["price"]
            )
        else:
            return apology("invalid symbol", 400)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Ensure username not empty
        if not username:
            return apology("must provide username", 400)

        # Ensure password not empty
        elif not password:
            return apology("must provide password", 400)

        # Ensure confirmation not empty
        elif not confirmation:
            return apology("must provide password confirmation", 400)

        # Ensure confirmation not empty
        elif not password == confirmation:
            return apology("passwords do not match", 400)

            # Ensure username already exist
        elif username:
            checkUsername = db.execute(
                "SELECT username FROM users WHERE username = ?", username
            )
            if checkUsername:
                return apology("username already exist", 400)
            else:
                print("Unique usename")

        db.execute(
            "INSERT INTO users (username, hash) VALUES(?, ?)",
            username,
            generate_password_hash(password),
        )
        print("Successful Register !")
        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
