import os
import requests
from fastapi import FastAPI
from pydantic import BaseModel
import json
from typing import List

app = FastAPI()

class Vuln(BaseModel):
    challenge_id: int
    port: int
    vuln_code: str
    custom_value: str
    flag: str

class Challenge(BaseModel):
    challenge_type: str
    vulns: List[Vuln]

template = '''filename:
    build: ./path/
    ports:
      - "port_number:8080"
    restart: unless-stopped'''
@app.get("/rundocker")
async def pwnapp():
    with open("Data.JSON", "r") as file:
        json_data = json.load(file)

    docker_compose_content = '''version: '3'
services:
  # Crypto Challenge

  # Pwn Challenges
'''
    
    json_list = list(json_data)
    for data in json_list:
        challenge_type = data['challenge_type']
        if challenge_type == 'pwn':
            for vuln in data['vulns']:
                challenge_id = vuln['challenge_id']
                port = vuln['port']
                vuln_code = vuln['vuln_code']
                custom_value = vuln['custom_value']
                flag = vuln['flag']
                temp = template
                temp = temp.replace("filename", vuln_code)
                temp = temp.replace("port_number", str(port))
                temp = temp.replace("path", custom_value)
                docker_compose_content+="  " +temp+"\n\n"
                print(temp)
                url = "http://10.212.172.184:8000/api/v1/challenges"
                headers = {
                    "Authorization": "Token aa39b3bad551c45215aa8640d701ce2e7f41508557289c06436f2ce52a15e998",
                    "Content-Type": "application/json"
                }
                json_data = {
                    "name": vuln_code,
                    "category": "pwn",
                    "description": "open powershell and put command http://127.0.0.1:8000 and run command nc localhost {}",
                    "type": "standard",
                    "value": 100,
                    "max_attempts": 20
                    }
                response = requests.post(url, headers=headers, json= json_data)

    with open("docker-compose.yml", "w") as f:
        f.write(docker_compose_content)

    
    print("Response Status Code:", response.status_code)
    print("Response Content:", response.content)
    
    if response.status_code == 200:
        os.system("docker-compose up --build")
        return {"message": "Pwn application is running"}
    else:
        return {"message": "An error occurred"}

# @app.post("/challenges")
# async def create_challenge(challenge: JSONData):
#     # Process the received challenge data
#     # You can access the values like challenge.id, challenge.type, etc.
#     # Perform necessary actions based on the data
#     return {"message": "Challenge created successfully"}


### Files
# c++ - use MACROs to enable or disable certain parts of the code
# flag.txt - take input from API
# Dockerfile - pre-configured, enable macro (env variable)
# docker-compose.yml  - take port from API

# FLAG = "FLAG{dummyflag}"

# /createChallenge  <--- parse user input, call appropriate function with data - Subhan is working on it


# CreatePwnChallenge(data) -- data["flag"], data["vuln"], data["port"], 
# --> createChallengeFiles 
# --> run_docker()
# --> pushToCTFd()


## createChallengeFiles - copy the following files in a separate challenge directory
### c++ - chatbot.cpp:
# * vulnerable application containing vulnerablities in its different functions
# * The vulnerablities can be enabled or disabled using c++ macros
# * only the requested vuln will be enabled as given in the API (through data["vuln"] parameter)
# * all vulns should in the end read the flag.txt file from the current working directory if exploited

### flag.txt
# * write a flag.txt file using the input from data["flag"]

### Dockerfile & docker-compose.yml
# * set MACRO according to the user input (data["vuln"])
# * set port (data["port"])

