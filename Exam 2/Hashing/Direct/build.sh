#!/bin/bash

g++ -Wall -std=c++17 main.cpp -o directhashing

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./directhashing
else
    printf "Build failed."
fi
