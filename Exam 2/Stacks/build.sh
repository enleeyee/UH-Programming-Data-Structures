#!/bin/bash

g++ -Wall -std=c++17 main.cpp -o standardstack

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./standardstack
else
    printf "Build failed."
fi
