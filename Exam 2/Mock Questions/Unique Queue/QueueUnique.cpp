#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class UniqueQueue {
private:
    Node* front;
    Node* rear;

    bool exists(int value) {
        Node* temp = front;
        while (temp) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

public:
    UniqueQueue() : front(nullptr), rear(nullptr) {}

    // Enqueue function (only adds unique values)
    void enqueue(int value) {
        if (exists(value)) {
            cout << "Value " << value << " already exists. Ignoring duplicate." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }

    void display() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    UniqueQueue uq;
    uq.enqueue(4);
    uq.enqueue(2);
    uq.enqueue(4);
    uq.enqueue(3);
    uq.enqueue(2);

    cout << "Queue after enqueue operations:" << endl;
    uq.display();

    return 0;
}
