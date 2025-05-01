#!/bin/bash

g++ -Wall -std=c++17 main.cpp Bellmanford.cpp -o bellmanford

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./bellmanford
else
    printf "Build failed."
fi
