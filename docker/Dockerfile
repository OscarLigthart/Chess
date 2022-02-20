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
LABEL version="1.0"
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

################################
# Create user
################################

RUN useradd -ms /bin/bash magnus
USER magnus

################################
# Build the application
################################

# go to home directory
WORKDIR /home/magnus

# clone the repo in the home directory (as this is all we will need)
RUN git clone https://github.com/OscarLigthart/Chess.git Chess

# create a build folder and enter it
RUN mkdir /home/magnus/Chess/chess/build
WORKDIR /home/magnus/Chess/chess/build

# compile the application
RUN cmake .. && \
    make

###############################
# Run application upon entry
###############################

ENTRYPOINT [ "/bin/bash", "-l", "-c", "./chess" ]
