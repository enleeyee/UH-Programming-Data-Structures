#include <iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;

    Node(int d, int p) : data(d), priority(p), next(nullptr) {}
};

class PriorityQueue {
private:
    Node* head;

public:
    PriorityQueue() : head(nullptr) {}

    // Function to insert a node based on priority
    void enqueue(int data, int priority) {
        Node* newNode = new Node(data, priority);

        // Case 1: Empty list or new node has lower priority than the head
        if (!head || priority < head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            // Case 2: Insert in the correct position
            Node* temp = head;
            while (temp->next && temp->next->priority <= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << "(" << temp->data << ", P" << temp->priority << ") -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(4, 2);
    pq.enqueue(5, 1);
    pq.enqueue(6, 3);
    pq.enqueue(7, 0);
    
    cout << "Priority Queue after enqueue operations:" << endl;
    pq.display();

    return 0;
}
