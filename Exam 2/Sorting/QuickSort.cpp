#include <iostream>
using namespace std;

void printArray(int myArray[], int start, int end) {
    for (int i = start; i <= end; i++)
        cout << myArray[i] << " ";
    cout << endl;
}

void Swap(int* a, int* b)
{
    int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int myArray[], int leftIndex, int rightIndex) {
    // select the rightmost element as pivot
    int pivot = myArray[rightIndex];
    cout << "\nPartitioning with pivot " << pivot << " at index " << rightIndex << endl;
    
    // pointer for greater element
    int i = (leftIndex - 1);
  
    // traverse each element of the array
    // compare them with the pivot
    for (int j = leftIndex; j < rightIndex; j++) {
      if (myArray[j] <= pivot) {
          
        // if element smaller than pivot is found, then swap it with the greater element pointed by i
        i++;
        
        // swap element at i with element at j
        Swap(&myArray[i], &myArray[j]);
      }
    }
    
    // swap pivot with the greater element at i
    Swap(&myArray[i + 1], &myArray[rightIndex]);

    cout << "Array after partitioning: ";
    printArray(myArray, leftIndex, rightIndex);
    
    // return the partition point
    return (i + 1);
  }

void QuickSort(int myArray[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        cout << "\nSorting range [" << leftIndex << "..." << rightIndex << "]\n";

        int pivotIndex = Partition(myArray, leftIndex, rightIndex);

        cout << "Left subarray [" << leftIndex << "..." << pivotIndex - 1 << "]: ";
        printArray(myArray, leftIndex, pivotIndex - 1);

        cout << "Right subarray [" << pivotIndex + 1 << "..." << rightIndex << "]: ";
        printArray(myArray, pivotIndex + 1, rightIndex);

        QuickSort(myArray, leftIndex, pivotIndex - 1);
        QuickSort(myArray, pivotIndex + 1, rightIndex);
    }
}

int main() {
    const int ARRAY_SIZE = 10;
    int myArray[ARRAY_SIZE] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    cout << "Start array: ";
    printArray(myArray, 0, ARRAY_SIZE - 1);

    QuickSort(myArray, 0, ARRAY_SIZE - 1);

    cout << "Sorted array: ";
    printArray(myArray, 0, ARRAY_SIZE - 1);

    return 0;
}
