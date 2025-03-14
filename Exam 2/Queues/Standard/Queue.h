#include <iostream>
using namespace std;

class InvalidQueueOperation {};

template <class T>
class Queue {
public:
    Queue();
    ~Queue();
    void Enqueue(T);
    T Dequeue();
    T Front();
    bool IsEmpty();
    void PrintQueue();

private:
    int front, rear, capacity, size;
    T* queue;
    void Resize();
};

template <class T>
Queue<T>::Queue() {
    front = 0;
    rear = -1;
    size = 0;
    capacity = 4;
    queue = new T[capacity];
}

template <class T>
Queue<T>::~Queue() {
    delete[] queue;
}

template <class T>
void Queue<T>::Resize() {
    int newCapacity = capacity * 2;
    T* newQueue = new T[newCapacity];

    // Copy elements to new array
    for (int i = 0; i < size; i++) {
        newQueue[i] = queue[(front + i) % capacity];
    }

    delete[] queue;
    queue = newQueue;
    capacity = newCapacity;
    front = 0;
    rear = size - 1;
}

template <class T>
void Queue<T>::Enqueue(T item) {
    if (size == capacity) {
        Resize();
    }

    rear = (rear + 1) % capacity;
    queue[rear] = item;
    size++;
}

template <class T>
T Queue<T>::Dequeue() {
    if (IsEmpty()) {
        throw InvalidQueueOperation();
    }

    T item = queue[front];
    front = (front + 1) % capacity;
    size--;

    return item;
}

template <class T>
T Queue<T>::Front() {
    if (IsEmpty()) {
        throw InvalidQueueOperation();
    }
    return queue[front];
}

template <class T>
bool Queue<T>::IsEmpty() {
    return size == 0;
}

template <class T>
void Queue<T>::PrintQueue() {
    cout << "Queue: ";
    for (int i = 0; i < size; i++) {
        cout << queue[(front + i) % capacity] << " ";
    }
    cout << endl;
}
