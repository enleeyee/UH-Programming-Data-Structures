#include "CircularLinkedList.h"
#include <iostream>

CircularLinkedList::CircularLinkedList() : tail(nullptr) {}

CircularLinkedList::~CircularLinkedList() {
    if (!tail) return;
    Node* curr = tail->next;
    do {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    } while (curr != tail->next);
    tail = nullptr;
}

void CircularLinkedList::Append(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!tail) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void CircularLinkedList::Print() {
    if (!tail) {
        std::cout << "List is empty\n";
        return;
    }
    Node* curr = tail->next;
    do {
        std::cout << curr->data << " ";
        curr = curr->next;
    } while (curr != tail->next);
    std::cout << std::endl;
}

void CircularLinkedList::Delete(int value) {
    if (!tail) return;

    Node* curr = tail->next;
    Node* prev = tail;

    do {
        if (curr->data == value) {
            if (curr == tail) {
                if (tail->next == tail) {
                    delete tail;
                    tail = nullptr;
                } else {
                    prev->next = curr->next;
                    delete curr;
                    tail = prev;
                }
            } else {
                prev->next = curr->next;
                delete curr;
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);
}

bool CircularLinkedList::IsEmpty() const {
    return tail == nullptr;
}
