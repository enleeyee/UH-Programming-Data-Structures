#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() {
    size = 0;
    head = nullptr;
}

LinkedList::~LinkedList() {
    Node* current;

    while (head != nullptr) {
        current = head;
        head = head->next;
        delete[] current;
    }

    head = nullptr;
    size = 0;
}

void LinkedList::Append(int value) {
    size++;

    if (head == nullptr) {
        head = new Node(value);
        return;
    }

    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = new Node(value);
}

int LinkedList::Get(int index) {
    Node* current = head;
    int count = 0;
    while (current != nullptr)
    {
        if (count == index) {
            return current->value;
        }
        count++;
        current = current->next;
    }

    return 0; // The default value
}

bool LinkedList::Find(int value) {
    Node* current = head;

    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }

        current = current->next;
    }

    return false;
}

void LinkedList::Insert(int index, int value) {
    size++;

    if (head == nullptr) { // Insert a new head
        head = new Node(value);
        return;
    }

    Node* current = head;
    if (index == 0) { // Insert as the head
        head = new Node(value, current);
        return;
    }

    int count = 1;

    while (current->next != nullptr) {
        if (count == index) {
            Node* temp = new Node(value, current->next);
            current->next = temp;
        }
        current = current->next;
        count++;
    }

    current->next = new Node(value);
}

bool LinkedList::IsEmpty() {
    return head == nullptr;
}

void LinkedList::Print() {
    Node* current = head;

    while (current != nullptr) {
        cout << current->value;
        if (current->next != nullptr) {
            cout << "->";
        }
        current = current->next;
    }

    cout << endl;
}

bool LinkedList::Delete(int value) {

    if (head == nullptr) { // Nothing to remove
        return false;
    }

    if (head->value == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    Node* previous = head;
    Node* current = head->next;

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

bool LinkedList::DeleteAt(int index) {

    if (head == nullptr || index < 0) { // Nothing to remove
        return false;
    }

    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    Node* previous = head;
    Node* current = head->next;
    
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

int LinkedList::Size() {
    return size;
}
