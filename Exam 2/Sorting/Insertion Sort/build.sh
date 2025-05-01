#!/bin/bash

g++ -Wall -std=c++17 InsertionSort.cpp -o isort

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./isort
else
    printf "Build failed."
fi
