#!/bin/bash

g++ -Wall -std=c++17 main.cpp -o arraylist

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./arraylist
else
    printf "Build failed."
fi
