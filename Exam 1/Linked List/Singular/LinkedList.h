#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#pragma once
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next = nullptr;
    Node(int val, Node* nxt = nullptr) { value = val; next = nxt; }
};

class LinkedList {
public:
    LinkedList();                      // Default Constructor
    ~LinkedList();                     // Destructor

    void Append(int value);            // Add a value to the end of the list
    int Get(int index);                // Return the value at the index requested, or 0
    bool Find(int value);              // Returns true if the value is found and false if not
    void Insert(int index, int value); // Insert value at index
    bool IsEmpty();                    // True if the list is currently empty
    void Print();
    bool Delete(int value);            // Delete the first occurrence of value; true if successful
    bool DeleteAt(int index);            // Delete the value at the location; true if successful
    int Size();                        // Number of elements in the list

private:
    Node* head;                        // Items are linked to the head
    int size;
};

#endif
