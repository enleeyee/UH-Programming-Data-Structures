#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main() {
    PriorityQueue<int> pq;

    cout << "Enqueuing elements with priorities." << endl;
    pq.Enqueue(10, 1); // Priority 1
    pq.Enqueue(20, 3); // Priority 3
    pq.Enqueue(30, 2); // Priority 2
    pq.Enqueue(40, 5); // Priority 5
    pq.Enqueue(50, 4); // Priority 4
    pq.PrintQueue();

    cout << "Dequeued: " << pq.Dequeue() << endl;
    pq.PrintQueue();

    cout << "Front element: " << pq.Front() << endl;
    pq.PrintQueue();

    return 0;
}
