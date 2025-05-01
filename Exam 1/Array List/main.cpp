#include <iostream>
#include "ArrayList.h"

using namespace std;

int main() {
   // Place your code here to test your solution
   ArrayList<int> intList;
   
   intList.Append(1);
   intList.Append(3);
   intList.Append(5);
   intList.Append(7);
   intList.Append(9);
   
   intList.Print();
   
   return 0;
}
