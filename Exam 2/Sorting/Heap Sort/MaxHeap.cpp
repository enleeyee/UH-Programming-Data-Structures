#include <iostream>
using namespace std;

void printArray(int myArray[], int size) {
    for(int i = 0; i < size; i++)
        cout << myArray[i] << " ";
    cout << endl;
}

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void HeapifyMax(int myArray[], int size, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < size && myArray[left] > myArray[largest])
      largest = left;
  
    if (right < size && myArray[right] > myArray[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        Swap(myArray[i], myArray[largest]);
        HeapifyMax(myArray, size, largest);
    }
}
  
void HeapSort(int myArray[], int size) {
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--)
        HeapifyMax(myArray, size, i);

    cout << "Heapified:" << endl;
    printArray(myArray, size);
    cout << endl;
  
    // Heap sort
    for (int i = size - 1; i >= 0; i--) {
        Swap(myArray[0], myArray[i]);
  
        // Heapify root element to get highest element at root again
        HeapifyMax(myArray, i, 0);
        printArray(myArray, size);
    }
}

int main() {
    const int ARRAY_SIZE = 10;
    int myArray[ARRAY_SIZE] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    cout << "Start array: ";
    printArray(myArray, ARRAY_SIZE);

    HeapSort(myArray, ARRAY_SIZE);

    cout << "Sorted array: ";
    printArray(myArray, ARRAY_SIZE);

    return 0;
}