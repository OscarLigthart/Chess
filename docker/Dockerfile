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
    && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

###############################
# GLFW
###############################
# used for rendering the game

# glfw dependencies
RUN apt-get update && \
    apt-get install --no-install-recommends --no-install-suggests --yes \
    xorg-dev \
    && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# clone the repo
RUN git clone https://github.com/glfw/glfw.git
WORKDIR /glfw
RUN git checkout 3.3.4

# build from source
RUN mkdir build
RUN cmake -S . -B build
WORKDIR /glfw/build
RUN make

# clean up
WORKDIR /
RUN rm -r /glfw
