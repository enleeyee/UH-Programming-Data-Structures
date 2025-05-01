#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* tail; // Points to last node (tail->next is head)

public:
    CircularLinkedList();
    ~CircularLinkedList();

    void Append(int value);       // Add to end
    void Print();                 // Print circular list
    void Delete(int value);       // Delete first occurrence
    bool IsEmpty() const;
};

#endif
