from cs50 import SQL
from flask import Flask, render_template, request
from helpers import random_string
import random

app = Flask(__name__) # สร้าง flask app on this file // __name__ is current file

db = SQL("sqlite:///history.db") # connect bd by using sqlite

app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.route("/", methods=["GET"]) # / is rootfolder, homepage, main page
def index():
    string = random_string(1000)
    return render_template("index.html", placeholder = string, name="ZUMO")
