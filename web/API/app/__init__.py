from flask import Flask
from .routes import register_routes
from .dbmodel import db

class LoggingMiddleware:
    def __init__(self, app):
        self._app = app

    def __call__(self, environ, start_response):
        print(f'Received request: {environ["REQUEST_METHOD"]} {environ["PATH_INFO"]}')
        return self._app(environ, start_response)

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

    # Add logging
    wsgi_app = LoggingMiddleware(app.wsgi_app)
    app.wsgi_app = wsgi_app
    return app
