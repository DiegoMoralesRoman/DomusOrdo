from flask_httpauth import HTTPBasicAuth
import os.path
import json

auth = HTTPBasicAuth()

CREDENTIALS_FILENAME = 'credentials.json'

# Get current directory
CURR_PATH = os.path.dirname(os.path.abspath(__file__))

credentials = {}

try:
    with open(os.path.join(CURR_PATH, CREDENTIALS_FILENAME), 'r') as file:
        credentials = json.load(file)
        print(credentials)
        if not 'username' in credentials or not 'password' in credentials:
            raise ValueError(f'''
    Credentials {credentials} 
    should contain the fields 'username' and 'password'
            ''')
except Exception as e:
    print("Faled to open credentials file")
    print(e)
    exit(1)
    
@auth.verify_password
def verify_password(username: str, password: str):
    print(f'''
    Logging in with username {username} and password {password}
    ''')
    if (credentials['username'] == username and credentials['password'] == password):
        print('Login successful')
        return True
    else:
        print('Login failed')
        return False
