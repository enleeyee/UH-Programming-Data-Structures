#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
   LinkedList intList;
   
   intList.Append(1);
   intList.Append(3);
   intList.Append(5);
   intList.Append(7);
   intList.Append(9);
   
   intList.Print();
   
   return 0;
}
