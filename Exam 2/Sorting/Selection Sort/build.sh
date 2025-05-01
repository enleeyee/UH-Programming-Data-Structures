#!/bin/bash

g++ -Wall -std=c++17 SelectionSort.cpp -o ssort

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./ssort
else
    printf "Build failed."
fi
