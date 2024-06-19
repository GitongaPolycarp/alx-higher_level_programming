#!/usr/bin/python3
"""
Script that takes in a URL and an email, sends a POST request to the passed
URL with the email as a parameter, and displays the body of the response
(decoded in utf-8).
"""
from sys import argv
from urllib.parse import urlencode
from urllib.request import Request, urlopen, URLError

if __name__ == "__main__":
    url = argv[1]
    value = {"email": argv[2]}
    data = urlencode(value).encode("ascii")
    req = Request(url, data)

    try:
        with urlopen(req) as response:
            print(response.read().decode("utf-8", "replace"))
    except URLError as e:
        print(f"Failed to make a request: {e.reason}")
