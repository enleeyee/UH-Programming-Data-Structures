#include <iostream>
using namespace std;

void printArray(int myArray[], int start, int end) {
    for (int i = start; i <= end; i++)
        cout << myArray[i] << " ";
    cout << endl;
}

void Merge(int myArray[], int leftIndex, int midIndex, int rightIndex, int depth) {
    int leftSize = midIndex - leftIndex + 1;
    int rightSize = rightIndex - midIndex;

    // Create temporary arrays
    int leftHalf[leftSize], rightHalf[rightSize];

    // Copy data to temporary arrays
    for (int i = 0; i < leftSize; i++)
        leftHalf[i] = myArray[leftIndex + i];

    for (int j = 0; j < rightSize; j++)
        rightHalf[j] = myArray[midIndex + 1 + j];

    cout << string(depth * 2, ' ') << "Merging: ";
    printArray(myArray, leftIndex, rightIndex);

    // Merge the temporary arrays back into myArray[leftIndex...rightIndex]
    int leftPos = 0, rightPos = 0, mergedPos = leftIndex;

    while (leftPos < leftSize && rightPos < rightSize) {
        if (leftHalf[leftPos] <= rightHalf[rightPos]) {
            myArray[mergedPos] = leftHalf[leftPos];
            leftPos++;
        } else {
            myArray[mergedPos] = rightHalf[rightPos];
            rightPos++;
        }
        mergedPos++;
    }

    // Copy the remaining elements of leftHalf[]
    while (leftPos < leftSize) {
        myArray[mergedPos] = leftHalf[leftPos];
        leftPos++;
        mergedPos++;
    }

    // Copy the remaining elements of rightHalf[]
    while (rightPos < rightSize) {
        myArray[mergedPos] = rightHalf[rightPos];
        rightPos++;
        mergedPos++;
    }

    cout << string(depth * 2, ' ') << "Merged:  ";
    printArray(myArray, leftIndex, rightIndex);
}

void MergeSort(int myArray[], int leftIndex, int rightIndex, int depth = 0) {
    if (leftIndex < rightIndex) {
        int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

        cout << string(depth * 2, ' ') << "Splitting: ";
        printArray(myArray, leftIndex, rightIndex);

        MergeSort(myArray, leftIndex, midIndex, depth + 1);
        MergeSort(myArray, midIndex + 1, rightIndex, depth + 1);

        Merge(myArray, leftIndex, midIndex, rightIndex, depth);
    }
}

int main() {
    const int ARRAY_SIZE = 10;
    int myArray[ARRAY_SIZE] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    cout << "Start array: ";
    printArray(myArray, 0, ARRAY_SIZE - 1);

    MergeSort(myArray, 0, ARRAY_SIZE - 1);

    cout << "Sorted array: ";
    printArray(myArray, 0, ARRAY_SIZE - 1);

    return 0;
}