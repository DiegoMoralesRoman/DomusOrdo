from typing import List
from flask import Flask, Blueprint
import os
import os.path
from dataclasses import dataclass
import importlib

@dataclass
class Route:
    """
    Represents a route with its associated data.
    """
    route: str
    filename: str
    blueprint: Blueprint

# List to store all routes
ROUTES: List[Route] = []

# Folder containing the routes
ROUTES_FOLDER = os.path.abspath(os.path.dirname(__file__))


def recursive_scan(path):
    """
    Recursively scan the given path for route files and populate the ROUTES list.
    """
    for elem in path:
        if str(os.path.basename(elem.path)).startswith('__'):
            continue

        if elem.is_dir():
            recursive_scan(os.scandir(elem))
        else:
            relative_path = os.path.relpath(elem.path, ROUTES_FOLDER)
            route = '/' + relative_path.removesuffix('.py')
            filename = os.path.abspath(elem.path)
            full_modname = f'.{relative_path.replace("/", ".").removesuffix(".py")}'
            print(full_modname)
            mod = importlib.import_module(full_modname, package=__package__)
            blueprint = getattr(mod, 'main_bp')
            ROUTES.append(Route(route=route, filename=filename, blueprint=blueprint))


def register_routes(app: Flask):
    """
    Register the routes in the Flask application.
    """
    for route in ROUTES:
        app.register_blueprint(
            route.blueprint,
            url_prefix=route.route
        )


for route in ROUTES:
    print(f'''
    Registered route:
        {route}
    ''')

# Scan the ROUTES_FOLDER to populate the ROUTES list
recursive_scan(os.scandir(ROUTES_FOLDER))
