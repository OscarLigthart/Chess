# Chess

This repo consists of a self implemented version of the game of Chess.

## Setup from source

### Prerequisites
This library requires SFML. To install it, run the following command:
```
sudo apt-get install libsfml-dev
```

### Installation
From the root of this repo, run the following commands:
```
mkdir build
cd build
cmake ..
make
```

## Docker 

You can also run this application in Docker. If you want to do so follow these steps:

### Creating the image
Create the docker image by running the following command:
```
docker build -t chess:latest ./docker
```

Then, run the image by using the following command

```
docker run --privileged --gpus all --net=host --runtime=nvidia -e DISPLAY=$DISPLAY chess
```
