#include <iostream>
#include <stdexcept>

using namespace std;

class InvalidPriorityQueueOperation {};

template <class T>
class PriorityQueue {
public:
    PriorityQueue();
    ~PriorityQueue();
    void Enqueue(T item, int priority);
    T Dequeue();
    T Front();
    bool IsEmpty();
    void PrintQueue();

private:
    int size, capacity;
    T* queue;
    int* priorities;
    void Resize();
    void HeapifyUp(int index);
    void HeapifyDown(int index);
};

template <class T>
PriorityQueue<T>::PriorityQueue() {
    size = 0;
    capacity = 4;
    queue = new T[capacity];
    priorities = new int[capacity];
}

template <class T>
PriorityQueue<T>::~PriorityQueue() {
    delete[] queue;
    delete[] priorities;
}

template <class T>
void PriorityQueue<T>::Resize() {
    int newCapacity = capacity * 2;
    T* newQueue = new T[newCapacity];
    int* newPriorities = new int[newCapacity];

    // Copy elements to new array
    for (int i = 0; i < size; i++) {
        newQueue[i] = queue[i];
        newPriorities[i] = priorities[i];
    }

    delete[] queue;
    delete[] priorities;
    queue = newQueue;
    priorities = newPriorities;
    capacity = newCapacity;
}

template <class T>
void PriorityQueue<T>::Enqueue(T item, int priority) {
    if (size == capacity) {
        Resize();
    }

    // Insert the item at the end
    queue[size] = item;
    priorities[size] = priority;
    size++;

    // Heapify the queue to maintain the priority order
    HeapifyUp(size - 1);
}

// Heapify upwards from a specific index
template <class T>
void PriorityQueue<T>::HeapifyUp(int index) {
    while (index > 0 && priorities[index] > priorities[(index - 1) / 2]) {
        // Swap with parent
        swap(queue[index], queue[(index - 1) / 2]);
        swap(priorities[index], priorities[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

template <class T>
T PriorityQueue<T>::Dequeue() {
    if (IsEmpty()) {
        throw InvalidPriorityQueueOperation();
    }

    // The element at the front is the one with the highest priority
    T item = queue[0];

    // Replace the front with the last element
    queue[0] = queue[size - 1];
    priorities[0] = priorities[size - 1];
    size--;

    // Heapify the queue to maintain the priority order
    HeapifyDown(0);

    return item;
}

// Heapify down from the root
template <class T>
void PriorityQueue<T>::HeapifyDown(int index) {
    while (2 * index + 1 < size) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        // Find the larger child
        int largerChild = leftChild;
        if (rightChild < size && priorities[rightChild] > priorities[leftChild]) {
            largerChild = rightChild;
        }

        // If the parent is larger than the larger child, break
        if (priorities[index] >= priorities[largerChild]) {
            break;
        }

        // Swap with the larger child
        swap(queue[index], queue[largerChild]);
        swap(priorities[index], priorities[largerChild]);

        index = largerChild;
    }
}

template <class T>
T PriorityQueue<T>::Front() {
    if (IsEmpty()) {
        throw InvalidPriorityQueueOperation();
    }
    return queue[0];
}

template <class T>
bool PriorityQueue<T>::IsEmpty() {
    return size == 0;
}

template <class T>
void PriorityQueue<T>::PrintQueue() {
    cout << "Priority Queue: ";
    for (int i = 0; i < size; i++) {
        cout << "[" << queue[i] << ", " << priorities[i] << "] ";
    }
    cout << endl;
}
