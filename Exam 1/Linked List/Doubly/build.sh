#!/bin/bash

g++ -Wall -std=c++17 main.cpp -o doublylinkedlist

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./doublylinkedlist
else
    printf "Build failed."
fi
