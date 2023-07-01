FROM ubuntu:22.04

RUN apt-get update && apt-get install -y g++ socat

RUN mkdir /data
WORKDIR /data
COPY int_overflow_2.cpp ./general.cpp
RUN g++ general.cpp -o general
RUN chmod 777 general
COPY flag.txt .

EXPOSE 8080

CMD socat TCP-LISTEN:8080,reuseaddr,fork EXEC:./general,pty,stderr,setsid,sigint,sane,raw,echo=0