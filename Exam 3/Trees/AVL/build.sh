#!/bin/bash

g++ -Wall -std=c++17 main.cpp AVL.cpp -o avl

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./avl
else
    printf "Build failed."
fi
