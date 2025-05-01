#!/bin/bash

g++ -Wall -std=c++17 QuickSort.cpp -o qsort

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./qsort
else
    printf "Build failed."
fi
