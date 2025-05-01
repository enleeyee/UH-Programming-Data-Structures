#!/bin/bash

g++ -Wall -std=c++17 PrioirityQueueLinkedList.cpp -o PQLL

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./PQLL
else
    printf "Build failed."
fi
