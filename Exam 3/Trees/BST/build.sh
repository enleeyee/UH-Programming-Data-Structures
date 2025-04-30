#!/bin/bash

g++ -Wall -std=c++17 main.cpp BST.cpp -o bst

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./bst
else
    printf "Build failed."
fi
