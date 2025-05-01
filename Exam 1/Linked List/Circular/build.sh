#!/bin/bash

g++ -Wall -std=c++17 main.cpp CircularLinkedList.cpp -o circularlinkedlist

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./circularlinkedlist
else
    printf "Build failed."
fi
