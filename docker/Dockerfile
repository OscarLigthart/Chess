#
# Dockerfile for running the chess game
#
# Auth: Oscar Ligthart
#
######################

# use ubuntu as base 
FROM ubuntu:20.04

# label about the custom image
LABEL maintainer="oscarligthart@gmail.com"
LABEL version="0.1"
LABEL description="This docker image is used to run the Chess game"

# Disable Prompt During Packages Installation
ARG DEBIAN_FRONTEND=noninteractive

###############################
# Requirements
###############################

RUN apt-get update && \
    apt-get install --no-install-recommends --no-install-suggests --yes \
    build-essential \
    git \
    ca-certificates \
    cmake \
    libsfml-dev \
    && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

