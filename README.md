# LevelDB with Rotating Skiplist
##### A Project by Jesse Galloway and Sam Paleologopoulos
Implementing Syncrobench's Rotating Skiplist into Google's LevelDB Key-Value store

## Deliverables
#### Benchmarks
We aim to create a benchmark consisting of a test running on three systems:
* [Stock LevelDB](https://github.com/google/leveldb)
* [Stock Rotating Skiplist](https://github.com/gramoli/synchrobench/tree/master/c-cpp/src/skiplists/rotating)
* LevelDB with Rotating Skiplist

We expect to see the Stock Rotating Skiplist perform the best, LevelDB the worst, and our custom implementation somewhere in the middle.
If we find that our custom implementation performs worse than the original LevelDB this could be indicitive of two things:
* We performed an incomplete implementation and there is a bottleneck leftover from the original skiplist in LevelDB
* The rotating skiplist is not well suited for the workload of LevelDB

#### Benchmark Results
**Stock LevelDB**
Using a scheme of randomly selecting between:
* 20% Inserts
* 70% Lookups
* 10% Deletes
We found the following:

| Opration Total  | Execution Time |
| ------------- | ------------- |
| 10,000  | 34.6ms  |
| 100,000  | 2576.1ms  |

## Changes
In order to implement the [rotating skiplist](https://github.com/gramoli/synchrobench/tree/master/c-cpp/src/skiplists/rotating) into [LevelDB](https://github.com/google/leveldb) the following files were updated in leveldb/db
* skiplist.h

## Recreate this Project
#### Docker
We created a Ubuntu docker image to run leveldb in:
```
docker pull ubuntu
```
Create the container using the dockerfile:
```dockerfile
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
```cmd
docker build -t cse_375 .
mkdir shared
```
Boot the container:
```cmd
docker run -e SHELL=/bin/bash --privileged -v "path\to\cd\shared:/root" --name cse_375_levelDB -it cse_375
```
Remove the container:
```cmd
docker rm cse_375_levelDB
```

#### Clone Repos
Syncrobench and LevelDB were cloned at the root of this repository

#### Building
LevelDB can be built with cmake from the leveldb directory, from the LevelDB repo README:
```bash
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build .
```
Syncrobench can be built by running make in the syncrobench directory

#### File Structure
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
