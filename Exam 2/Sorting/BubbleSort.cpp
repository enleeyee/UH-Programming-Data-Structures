#include <iostream>
using namespace std;

void printArray(int myArray[], int size) {
    for(int i = 0; i < size; i++)
        cout << myArray[i] << " ";
    cout << endl;
}

void BubbleSort(int myArray[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (myArray[j] > myArray[j + 1]) {
                int temp = myArray[j];
                myArray[j] = myArray[j + 1];
                myArray[j + 1] = temp;
            }
        }

        cout << "At step " << i << " : ";
        printArray(myArray, size);
    }
}

int main() {
    const int ARRAY_SIZE = 10;
    int myArray[ARRAY_SIZE] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    cout << "Start array: ";

    printArray(myArray, ARRAY_SIZE);

    BubbleSort(myArray, ARRAY_SIZE);

    cout << "Sorted array: ";

    printArray(myArray, ARRAY_SIZE);
        
    return 0;
}