import requests
import sys

def get_github_id(username, password):
    url = 'https://api.github.com/user'
    response = requests.get(url, auth=(username, password))
    if response.status_code == 200:
        return response.json().get('id')
    else:
        return None

if __name__ == "__main__":
    username = sys.argv[1]
    password = sys.argv[2]
    print(get_github_id(username, password))
