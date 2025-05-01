#pragma once
#include <iostream>
using namespace std;

template<typename T> 
class ArrayList {
   public:
      ArrayList();                     // Default Constructor
      ~ArrayList();                    // Destructor
      
      void Append(T value);            // Add a value to the end of the list
      T At(int index, T value);        // Return the element at index or the default value
      int Capacity();                  // Return the current maximum capacity of the array list
      int Find(T value);               // Return index of first occurrence of value or -1 if not found
      void Insert(int index, T value); // Insert value at index
      bool IsEmpty();                  // True if the list is currently empty
      void Print();
      bool Remove(T value);            // Find the first occurrence of value and remove the value; true if success
      bool RemoveAt(int index);        // Remove the value at the specified index; true if success
      int Size();                      // Number of elements in the list

   private:
      T* list;                         // Items are stored in this dynamic array
      int size, capacity;
};

template<typename T>
ArrayList<T>::ArrayList(){
   size = 0;
   capacity = 8;
   list = new T[capacity];
}

template<typename T>
ArrayList<T>::~ArrayList() {
   delete[] list;
   list = nullptr;
   size = 0;
   capacity = 0;
}

template<typename T>
void ArrayList<T>::Append(T value){
   if(size == capacity) { // Need to allocate more space
      capacity *= 2;
      T* temp = new T[capacity];
      for(int i = 0; i < size; i++){
         temp[i] = list[i];
      }
      delete[] list;
      list = temp;
   }
   
   list[size] = value;
   size++;
}

template<typename T>
T ArrayList<T>::At(int index, T value){
   if(index >=0 && index < size){
      return list[index];
   }
   
   return value;
}

template<typename T>
int ArrayList<T>::Capacity(){
   return capacity;
}

template<typename T>
int ArrayList<T>::Find(T value){
   for (int i = 0; i < size; i++) {
      if (value == list[i]) {
         return i;
      }
   }

   return -1;
}

template<typename T>
void ArrayList<T>::Insert(int index, T value){
   if(index < 0) { // Nothing to do here
      return;
   }
   
   if(size == capacity) { // Need to allocate more space
      capacity *= 2;
      T* temp = new T[capacity];
      for(int i = 0; i < size; i++){
         temp[i] = list[i];
      }
      delete[] list;
      list = temp;
   }
   
   for(int i = size; i > index; i--){
      list[i] = list[i-1]; // Shift the array up   
   }
   
   list[index] = value;
   size++;
}

template<typename T>
bool ArrayList<T>::IsEmpty(){
   return size == 0;
}

template<typename T>
void ArrayList<T>::Print(){
   for (int i = 0; i < size; i++) {
      cout << list[i];
      if (i < size-1) {
         cout << ", ";
      }
   }   
   cout << endl;
}

template<typename T>
bool ArrayList<T>::Remove(T value) {
   int loc = Find(value);
   if(loc < 0){
      return false;
   }
   
   size--;
   for(int i = loc; i < size; i++){
      list[i] = list[i+1]; // Shift the array down
   }
   
   return true;
}

template<typename T>
bool ArrayList<T>::RemoveAt(int index){
   if(index < 0 || index >= size){
      return false;
   }
   
   size--;
   for(int i = index; i < size; i++){
      list[i] = list[i+1]; // Shift the array down
   }
   
   return true;
}

template<typename T>
int ArrayList<T>::Size() {
   return size;
}
