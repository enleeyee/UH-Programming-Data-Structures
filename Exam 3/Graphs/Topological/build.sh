#!/bin/bash

g++ -Wall -std=c++17 main.cpp Toposort.cpp -o toposort

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./toposort
else
    printf "Build failed."
fi
