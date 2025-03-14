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
 
void HeapifyMin(int *myArray, int size, int i) {
    // Find smallest among root, left child and right child
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < size && myArray[left] < myArray[smallest])
       smallest = left;
       
    if(right < size && myArray[right] < myArray[smallest])
       smallest = right;
       
    // Swap and continue heapifying if root is not smallest
    if(smallest != i) {
       Swap(myArray[i], myArray[smallest]);
       
       HeapifyMin(myArray, size, smallest);
    }
}
 
void HeapSort(int myArray[], int size) {
    // Build min heap
    for(int i = size / 2 - 1; i >= 0; i--)
       HeapifyMin(myArray, size, i);
       
    cout << "Heapified:" << endl;
    printArray(myArray, size);
    cout << endl;
    
    // Heap sort
    for(int i = size - 1; i > 0; i--) {
       Swap(myArray[0], myArray[i]);
       
       // Heapify root element to get smallest element at root again
       HeapifyMin(myArray, i, 0);
       printArray(myArray, size);
    }
}

int main() {
    const int ARRAY_SIZE = 10;
    int myArray[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Start array: ";
    printArray(myArray, ARRAY_SIZE);

    HeapSort(myArray, ARRAY_SIZE);

    cout << "Sorted array: ";
    printArray(myArray, ARRAY_SIZE);

    return 0;
}