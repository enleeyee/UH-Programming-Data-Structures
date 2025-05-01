#!/bin/bash

g++ -Wall -std=c++17 main.cpp Floydwarshall.cpp -o floydwarshall

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./floydwarshall
else
    printf "Build failed."
fi
