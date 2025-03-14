#include <iostream>
using namespace std;

class InvalidStackOperation {};

template <class T> 
class Stack {
public:
   Stack();
   ~Stack();
   void Push(T);
   T Pop();
   T Top();
   bool IsEmpty();
 
private:
   int top, capacity;
   T* stack;
};
 
template <class T> 
Stack<T>::Stack() {
   top = -1;
   capacity = 4;
   stack = new T[4];
}

template <class T> 
Stack<T>::~Stack() {
   delete[] stack;
}

template <class T> 
void Stack<T>::Push(T item) {
   if(top == capacity - 1) { // Full!
      capacity *= 2;
      T* temp = new T[capacity];
      for(int i = 0; i <= top; i++){
         temp[i] = stack[i];   
      }
      delete[] stack;
      stack = temp;
   }
   
   top = top + 1;
   
   stack[top] = item;
}
 

template <class T> 
bool Stack<T>::IsEmpty() {
   if (top == -1)
      return true;
   else
      return false;
}
 
template <class T> 
T Stack<T>::Pop() {
   if(top == -1){
      throw InvalidStackOperation();
   }
   
   T item = stack[top];
   top--;
 
   return item;
}

template <class T> 
T Stack<T>::Top() {
   if(top == -1){
      throw InvalidStackOperation();
   }
   T item = stack[top];
 
   return item;
}
