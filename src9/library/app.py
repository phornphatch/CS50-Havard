from cs50 import SQL
from flask import Flask, render_template, request
from helpers import random_string
import random

app = Flask(__name__) # สร้าง flask app on this file // __name__ is current file

db = SQL("sqlite:///history.db") # connect bd by using sqlite

app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.route("/", methods=["GET", "POST"]) # / is rootfolder, homepage, main page
def index():
    if request.method == "POST":
        page = request.form.get("page")

        try:
            page = int(page)
        except ValueError:
            return render_template("index.html", random_string="Enter a Number !")

        if page < 0:
            return render_template("index.html", random_string="Type positive number !")

        db.execute("INSERT INTO history (page) VALUES (?)", page) # *** เขียน sql ใน python ใช้ db.execute ***
        random.seed(page) # ทำให้ ถ้าหน้าเดิม random string จะออกมาเหมือนเดิม

    string = random_string(1000)
    rows = db.execute("SELECT * FROM history;")
    return render_template("index.html", random_string=string, name="ZUMO", data=rows)
