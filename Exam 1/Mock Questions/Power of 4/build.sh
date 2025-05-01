#!/bin/bash

g++ -Wall -std=c++17 main.cpp -o poweroffour

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./poweroffour
else
    printf "Build failed."
fi
