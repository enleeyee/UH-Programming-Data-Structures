#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
   Stack<int> intStack;
   Stack<string> stringStack;

   intStack.Push(2);
   intStack.Push(3);
   intStack.Push(4);

   stringStack.Push("Last");
   stringStack.Push("For");
   stringStack.Push("The Best");

   cout << "Emptying the stacks:" << endl;
   while(!intStack.IsEmpty()){
      cout << intStack.Pop() << endl;
   }
   
   while(!stringStack.IsEmpty()){
      cout << stringStack.Top() << endl;
      stringStack.Pop();
   }
   
   return 0;
}
