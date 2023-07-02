from flask import Flask
from .routes import register_routes
import os
from .dbmodel import db

def create_app(config_path: str = 'config.py') -> Flask:
    app = Flask(__name__)

    # Configure application
    app.config.from_pyfile(config_path)

    # Configure database
    db.init_app(app)
    with app.app_context():
        db.create_all()

    # Register routes
    register_routes(app)

    return app
