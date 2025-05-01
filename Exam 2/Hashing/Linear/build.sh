#!/bin/bash

g++ -Wall -std=c++17 main.cpp -o linearhashing

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./linearhashing
else
    printf "Build failed."
fi
