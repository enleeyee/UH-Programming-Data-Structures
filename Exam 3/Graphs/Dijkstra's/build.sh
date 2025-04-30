#!/bin/bash

g++ -Wall -std=c++17 main.cpp Dijkstra.cpp -o dijkstra

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./dijkstra
else
    printf "Build failed."
fi
