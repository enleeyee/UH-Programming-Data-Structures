#!/bin/bash

g++ -Wall -std=c++17 main.cpp LinkedList.cpp -o graph

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./graph
else
    printf "Build failed."
fi
