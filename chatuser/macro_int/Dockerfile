FROM ubuntu:22.04

RUN apt-get update && apt-get install -y g++ socat

RUN mkdir /data
WORKDIR /data/chatuser/macro_buffer
COPY ../chatwithuser.cpp ./general.cpp
ARG INTEGER_OVERFLOW 
ARG BUFFER_SIZE 
RUN g++ general.cpp -o general -D"INTEGER_OVERFLOW=${INTEGER_OVERFLOW}" -D"BUFFER_SIZE=${BUFFER_SIZE}"
RUN chmod 777 general
COPY ../flag.txt .

EXPOSE 8080

CMD socat TCP-LISTEN:8080,reuseaddr,fork EXEC:./general,pty,stderr,setsid,sigint,sane,raw,echo=0