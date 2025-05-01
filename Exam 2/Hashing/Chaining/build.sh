#!/bin/bash

g++ -Wall -std=c++17 main.cpp -o chainhashing

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./chainhashing
else
    printf "Build failed."
fi
