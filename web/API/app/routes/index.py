from typing import List
from flask import Blueprint, render_template
from dataclasses import dataclass

from ..dbmodel import db, Project

main_bp = Blueprint('main', __name__)

@main_bp.route('/')
def index():
    projects = Project.query.all()
    for proj in projects:
        print(proj.description)
    return render_template('index.html',
        projects=projects
    )



