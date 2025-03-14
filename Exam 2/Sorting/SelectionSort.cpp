#include <iostream>
using namespace std;

void printArray(int myArray[], int size) {
    for(int i = 0; i < size; i++)
        cout << myArray[i] << " ";
    cout << endl;
}

void Swap(int myArray[], int j, int k) {
    if(j != k) {
        int temp = myArray[j];
        myArray[j] = myArray[k];
        myArray[k] = temp;
    }
 }
 
 void SelectionSort(int myArray[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int indexSmallest = i;
        for (int j = i + 1; j < size; ++j) {
            if ( myArray[j] < myArray[indexSmallest] ) {
                indexSmallest = j;
            }
        }
        Swap(myArray, i, indexSmallest);
        
        cout << "At step " << i << " : ";
        printArray(myArray, size);
    }
 }

int main() {
    const int ARRAY_SIZE = 10;
    int myArray[ARRAY_SIZE] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    cout << "Start array: ";

    printArray(myArray, ARRAY_SIZE);

    SelectionSort(myArray, ARRAY_SIZE);

    cout << "Sorted array: ";

    printArray(myArray, ARRAY_SIZE);
        
    return 0;
}
