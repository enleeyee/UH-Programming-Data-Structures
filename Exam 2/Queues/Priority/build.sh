#!/bin/bash

g++ -Wall -std=c++17 main.cpp -o prioirityqueue

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./prioirityqueue
else
    printf "Build failed."
fi
