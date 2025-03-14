#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue<int> q;

    cout << "Enqueuing 4 elements: 10, 20, 30, 40" << endl;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.PrintQueue();

    cout << "Dequeued: " << q.Dequeue() << endl;
    q.PrintQueue();

    cout << "Enqueuing 50, 60" << endl;
    q.Enqueue(50);
    q.Enqueue(60);
    q.PrintQueue();

    cout << "Dequeued: " << q.Dequeue() << endl;
    q.PrintQueue();

    cout << "Front element: " << q.Front() << endl;
    return 0;
}
