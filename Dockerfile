FROM debian:bullseye

RUN apt update && apt install -y build-essential make
RUN echo 'alias l="ls -la"' >> ~/.bashrc