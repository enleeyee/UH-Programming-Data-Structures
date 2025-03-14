#include <iostream>
using namespace std;

void printArray(int myArray[], int size) {
    for(int i = 0; i < size; i++)
        cout << myArray[i] << " ";
    cout << endl;
}

void Swap(int myArray[], int j, int k) {
    int temp = myArray[j];
    myArray[j] = myArray[k];
    myArray[k] = temp;
}
 
void InsertionSort(int myArray[], int size) {
    for (int i = 1; i < size; ++i) {
        int j = i;
        while (j > 0) {
            if (myArray[j] < myArray[j - 1]) {
                Swap(myArray, j, j  - 1);
                --j;
            }
            else {
                break;
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

    InsertionSort(myArray, ARRAY_SIZE);

    cout << "Sorted array: ";

    printArray(myArray, ARRAY_SIZE);
        
    return 0;
}