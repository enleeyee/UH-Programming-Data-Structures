#!/bin/bash

g++ -Wall -std=c++17 MergeSort.cpp -o msort

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./msort
else
    printf "Build failed."
fi
