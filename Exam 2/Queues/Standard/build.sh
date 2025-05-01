#!/bin/bash

g++ -Wall -std=c++17 main.cpp -o standardqueue

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./standardqueue
else
    printf "Build failed."
fi
