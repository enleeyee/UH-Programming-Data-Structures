#!/bin/bash

g++ -Wall -std=c++17 MaxHeap.cpp -o mheap

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./mheap
else
    printf "Build failed."
fi
