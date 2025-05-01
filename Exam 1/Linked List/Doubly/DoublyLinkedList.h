#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct Node {
    T value;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
    Node(T val, Node<T>* nxt = nullptr, Node<T>* prv = nullptr) { value = val; next = nxt; prev = prv; }
};

template<typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();                      // Default Constructor
    ~DoublyLinkedList();                     // Destructor

    void Append(T value);              // Add a value to the end of the list
    T operator[](int index);           // Return the value at the index requested
    bool Find(T value);                // Returns true if the value is found and false if not
    void Insert(int index, T value);   // Insert value at index
    bool IsEmpty();                    // True if the list is currently empty
    void Print();
    void PrintReverse();
    bool Delete(T value);              // Delete the first occurrence of value; true if successful
    bool DeleteAt(int index);          // Delete the value at the location; true if successful
    int Size();                        // Number of elements in the list

private:
    Node<T>* head;                     // Items are linked to the head
    int size;
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    size = 0;
    head = nullptr;
}
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* current;

    while (head != nullptr) {
        current = head;
        head = head->next;
        delete current;
    }

    head = nullptr;
    size = 0;
}

template<typename T>
void DoublyLinkedList<T>::Append(T value) {
    size++;

    if (head == nullptr) {
        head = new Node<T>(value);
        return;
    }

    Node<T>* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = new Node<T>(value, nullptr, current);
}

template<typename T>
T DoublyLinkedList<T>::operator[](int index) {
    Node<T>* current = head;
    if(index < 0){
       index += size;
    }
    
    int count = 0;
    while (current != nullptr)
    {
        if (count == index) {
            return current->value;
        }
        count++;
        current = current->next;
    }

    return head->value; // The default value
}

template<typename T>
bool DoublyLinkedList<T>::Find(T value) {
    Node<T>* current = head;

    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }

        current = current->next;
    }

    return false;
}

template<typename T>
void DoublyLinkedList<T>::Insert(int index, T value) {
    if(index < 0){
       index += size;
    }
    
    size++;

    if (head == nullptr) { // Insert a new head
        head = new Node<T>(value);
        return;
    }

    Node<T>* current = head;
    if (index == 0) { // Insert as the head
        head = new Node<T>(value, current);
        return;
    }

    int count = 1;

    while (current->next != nullptr) {
        if (count == index) {
            Node<T>* temp = new Node<T>(value, current->next);
            current->next = temp;
        }
        current = current->next;
        count++;
    }

    current->next = new Node<T>(value);
}

template<typename T>
bool DoublyLinkedList<T>::IsEmpty() {
    return head == nullptr;
}

template<typename T>
void DoublyLinkedList<T>::Print() {
    Node<T>* current = head;

    while (current != nullptr) {
        cout << current->value;
        if (current->next != nullptr) {
            cout << "->";
        }
        current = current->next;
    }

    cout << endl;
}

template<typename T>
void DoublyLinkedList<T>::PrintReverse() {
    Node<T>* current = head;
    while (current->next != nullptr) {
       current = current->next;
    }

    while (current != nullptr) {
        cout << current->value;
        if (current->prev != nullptr) {
            cout << "->";
        }
        current = current->prev;
    }

    cout << endl;
}

template<typename T>
bool DoublyLinkedList<T>::Delete(T value) {

    if (head == nullptr) { // Nothing to remove
        return false;
    }

    if (head->value == value) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    Node<T>* previous = head;
    Node<T>* current = head->next;

    while (current != nullptr) {
        if (current->value == value) {
            previous->next = current->next;
            delete current;
            size--;
            return true;
        }

        previous = current;
        current = current->next;
    }

    return false;
}

template<typename T>
bool DoublyLinkedList<T>::DeleteAt(int index) {
   if(index < 0){
      index += size;
   }
   
    if (head == nullptr || index >= size) { // Nothing to remove
        return false;
    }

    if (index == 0) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    Node<T>* previous = head;
    Node<T>* current = head->next;
    
    int count = 1;

    while (current->next != nullptr) {
        if (count == index) {
            previous->next = current->next;
            delete current;
            size--;
            return true;
        }
        
        previous = current;
        current = current->next;
        count++;
    }

   return false;    
}

template<typename T>
int DoublyLinkedList<T>::Size() {
    return size;
}

#endif
