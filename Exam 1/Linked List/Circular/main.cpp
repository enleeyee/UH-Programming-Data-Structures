#include <iostream>
#include "CircularLinkedList.h"

int main() {
    CircularLinkedList list;

    list.Append(10);
    list.Append(20);
    list.Append(30);

    std::cout << "Circular List: ";
    list.Print();

    list.Delete(20);
    std::cout << "After deleting 20: ";
    list.Print();

    list.Delete(10);
    list.Delete(30);
    std::cout << "After deleting all: ";
    list.Print();

    return 0;
}
