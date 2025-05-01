#!/bin/bash

g++ -Wall -std=c++17 BubbleSort.cpp -o bsort

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./bsort
else
    printf "Build failed."
fi
