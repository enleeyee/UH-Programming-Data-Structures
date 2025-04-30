#!/bin/bash

g++ -Wall -std=c++17 main.cpp Kruskal.cpp -o kruskal

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./kruskal
else
    printf "Build failed."
fi
