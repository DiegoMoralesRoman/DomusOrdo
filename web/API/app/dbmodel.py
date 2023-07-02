from typing import Optional
from flask_sqlalchemy import SQLAlchemy
from flask import Flask

db = SQLAlchemy()

class Project(db.Model):
    codename = db.Column(db.String(50), primary_key=True)
    name = db.Column(db.String(100))
    description = db.Column(db.Text)
    visits = db.Column(db.Integer)

    def __init__(self, codename, name, description, visits=0):
        self.codename = codename
        self.name = name
        self.description = description
        self.visits = visits

