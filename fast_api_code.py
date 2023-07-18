
import logging
import os
from fastapi import Request
import shutil
from fastapi import FastAPI
from pydantic import BaseModel
import json
from typing import List
from fastapi.middleware.cors import CORSMiddleware

app = FastAPI()
origins = [
    "http://localhost", "http://127.0.0.1:8000"
]

app.add_middleware(
    CORSMiddleware,
    allow_origins=origins,
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)
class Vuln(BaseModel):
    challenge_id: int
    port: int
    file_name: str
    directory: str
    flag: str
    macros: str
    macros_value: int
    subfolder_name: str
    buffer_size: int
    function_name: str
    # returnType: str
    # parameters: str
    cpp_code: str

class Challenge(BaseModel):
    challenge_type: str
    vulns: List[Vuln]

template = '''fileName:
    build:
      context: ./path/
      dockerfile: ./subfolder/Dockerfile
      args:
        - macros=macros_value
        - BUFFER_SIZE=buffer_size  
    ports:
      - "port_number:8080"
    restart: unless-stopped'''


@app.post("/")
async def main(request: Request):
    data = await request.json()
    print(data)
    return {"message:" "Hello world"}
@app.post("/rundocker")
async def pwnapp(request: Request):
    data = await request.json()
    # with open("Data.JSON", "r") as file:
    # print(data)
    json_data = json.loads(data)

    docker_compose_content = '''version: '3'
services:
'''
    docker_content_up = '''FROM ubuntu:22.04

RUN apt-get update && apt-get install -y g++ socat

RUN mkdir /data
WORKDIR /data/chatuser/directory
COPY ../chatwithuser.cpp ./general.cpp
'''
    docker_content_in = ''''''
    
    macro_define = ''
    docker_content_low = '''RUN chmod 777 general
COPY ../flag.txt .

EXPOSE 8080

CMD socat TCP-LISTEN:8080,reuseaddr,fork EXEC:./general,pty,stderr,setsid,sigint,sane,raw,echo=0'''

    base_path = "chatuser"
    libraries_template = '''#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#include <algorithm>
'''

    cpp_template = '''

int main()
{
    functionName
    return 0;
}
'''
    cpp_function = ''
    function_names = ''
   
    for data in json_data:
        challenge_type = data['challenge_type']
        if challenge_type == 'pwn':
            for vuln in data['vulns']:
                challenge_id = vuln['challenge_id']
                macros = vuln['macros']
                macros_value = vuln['macros_value']
                port = vuln['port']
                file_name = vuln['file_name']
                directory = vuln['directory']
                flag = vuln['flag']
                subfolder_name = vuln['subfolder_name']
                buffer_size = vuln['buffer_size']
                function_name = vuln['function_name']
                # returnType= vuln['returnType']
                # parameters= vuln['parameters']
                cpp_code= vuln['cpp_code']
                print(macros)


                #Replacing variables in docker-compose.yml file
                temp_composer = template
                temp_composer = temp_composer.replace("macros", macros)
                temp_composer = temp_composer.replace("fileName", file_name)
                temp_composer = temp_composer.replace("macros_value", str(macros_value))
                temp_composer = temp_composer.replace("port_number", str(port))
                temp_composer = temp_composer.replace("path", directory)
                temp_composer = temp_composer.replace("buffer_size", str(buffer_size))
                temp_composer = temp_composer.replace("subfolder", subfolder_name)
                docker_compose_content += "  " + temp_composer + "\n\n"
               
               
                #updating variables in Dockerfile
                # temp = docker_content_in_template.replace("macros", macros)
                temp = f'ARG {macros} \n'
                temp2 = f'ARG BUFFER_SIZE \n'
                macro_define = f'-D"{macros}=${{{macros}}}" -D"BUFFER_SIZE=${{BUFFER_SIZE}}"'
                print(macro_define)
                docker_content_up = docker_content_up.replace("directory", subfolder_name)
                docker_content_in =  f'RUN g++ general.cpp -o general {macro_define}\n'
                            # {returnType} {functionName}({parameters})
                

                cpp_function += cpp_code + '\n'
                function_names += function_name + '();\n    '
        
               
                #creating subfloder and Dockerfile in it
                subfolder_path = os.path.join(base_path, subfolder_name)
                if not os.path.exists(subfolder_path):
                    os.mkdir(subfolder_path)
                    dockerfile_content = docker_content_up+temp+ temp2+docker_content_in+docker_content_low
                    dockerfile_path = os.path.join(subfolder_path, "Dockerfile")
                    with open(dockerfile_path, "w") as f:
                        f.write(dockerfile_content)
                else:
                    print("directory already exist with same name")
            
             
                # deploying challenges on ctf-D through API
                # url = "http://10.212.172.184:8000/api/v1/challenges"
                # headers = {
                #     "Authorization": "Token aa39b3bad551c45215aa8640d701ce2e7f41508557289c06436f2ce52a15e998",
                #     "Content-Type": "application/json"
                # }
                # json_data = {
                #     "name": file_name,
                #     "category": "pwn",
                #     "description": "open powershell and put command http://127.0.0.1:8000 and run command nc localhost {port}",
                #     "type": "standard",
                #     "value": 100,
                #     "max_attempts": 20
                #     }
                # response = requests.post(url, headers=headers, json= json_data)
         # Remove the last occurrence of "functionName" in main()
        # cpp_content = cpp_content.replace("functionName", "")
        # cpp_content = libraries_template + overwrite + cpp_func_call
        cpp_template = cpp_template.replace("functionName", function_names)
        cpp_content = libraries_template + cpp_function + cpp_template
        with open('./chatuser/chatwithuser.cpp', 'w') as file:
            file.write(cpp_content)

        #writing docker-compose.yml file
        with open("docker-compose.yml", "w") as f:
            f.write(docker_compose_content)
       
       
    #building docker
    # if response.status_code == 200:
        os.system("docker-compose up --build -d")
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

