#!/bin/bash

g++ -Wall -std=c++17 main.cpp Prim.cpp -o prim

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./prim
else
    printf "Build failed."
fi
