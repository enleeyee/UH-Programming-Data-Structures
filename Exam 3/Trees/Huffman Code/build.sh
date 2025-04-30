#!/bin/bash

g++ -Wall -std=c++17 main.cpp Huffman.cpp -o huffman

if [ $? -eq 0 ]; then
    printf "Build successful. \nRunning program: \n"
    ./huffman
else
    printf "Build failed."
fi
