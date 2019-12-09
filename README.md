# LevelDB with Rotating Skiplist
Implementing Syncrobench's Rotating Skiplist into Google's LevelDB Key-Value store

### Installation
#### Docker
We created a Ubuntu docker image to run leveldb in:
```
docker pull ubuntu
```
Create the container using the dockerfile:
```
# Dockerfile to build a container for CSE303 development
FROM ubuntu
MAINTAINER Jesse Galloway (jsg220@lehigh.edu)

# Initialize repos and upgrade the base system
RUN apt-get update -y
RUN apt-get upgrade -y

# Install additional software needed for development
RUN apt-get install -y git man curl build-essential screen gdb libssl-dev psmisc
RUn apt-get -y install cmake

# Change the working directory:
WORKDIR "/root"
```
In the directory of the Dockerfile, built the container once and create a shared directory:
```
docker build -t cse_375 .
mkdir shared
```
Boot the container:
```
docker run -e SHELL=/bin/bash --privileged -v "path\to\cd\shared:/root" --name cse_375_levelDB -it cse_375
```
Remove the container:
```
docker rm cse_375_levelDB
```

## Building
LevelDB can be built with cmake, from the LevelDB repo README:
```
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build .
```

This repo assumes the following file structure:
```
leveldb_rotating_skiplist (this repo)
|
|--leveldb
|   |
|   |--build
|   |
|   |--include
|   |
|   ...
|
|--tests
    |
    |
```