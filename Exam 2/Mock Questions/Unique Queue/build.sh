#!/bin/bash

g++ -Wall -std=c++17 QueueUnique.cpp -o QU

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./QU
else
    printf "Build failed."
fi
