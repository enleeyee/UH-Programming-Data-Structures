#include <iostream>
#include "ChainingHashing.h"
using namespace std;

int main() {
    ChainingHashing<int> hashTable(10);

    hashTable.Insert(10);
    hashTable.Insert(20);
    hashTable.Insert(30);
    hashTable.Insert(15);
    hashTable.Insert(25);

    hashTable.Display();

    hashTable.Delete(15);
    hashTable.Delete(25);
    hashTable.Delete(50);

    hashTable.Display();

    return 0;
}
