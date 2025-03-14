#include <iostream>
#include <stdexcept>
using namespace std;

class InvalidHashOperation {};

template <typename T>
class DirectHashing {
public:
    DirectHashing(int maxKey);
    ~DirectHashing();
    
    void Insert(int key, T value);
    T Search(int key);
    void Delete(int key);
    bool IsEmpty(int key);

private:
    int maxKey;
    T* hashTable;
};

template <typename T>
DirectHashing<T>::DirectHashing(int maxKey) {
    this->maxKey = maxKey;
    hashTable = new T[maxKey];
    for (int i = 0; i < maxKey; i++) {
        hashTable[i] = T();
    }
}

template <typename T>
DirectHashing<T>::~DirectHashing() {
    delete[] hashTable;
}

template <typename T>
void DirectHashing<T>::Insert(int key, T value) {
    if (key >= maxKey || key < 0) {
        throw InvalidHashOperation();
    }
    
    hashTable[key] = value;
}

template <typename T>
T DirectHashing<T>::Search(int key) {
    if (key >= maxKey || key < 0) {
        throw InvalidHashOperation();
    }
    
    return hashTable[key];
}

template <typename T>
void DirectHashing<T>::Delete(int key) {
    if (key >= maxKey || key < 0) {
        throw InvalidHashOperation();
    }
    
    hashTable[key] = T();
}

template <typename T>
bool DirectHashing<T>::IsEmpty(int key) {
    if (key >= maxKey || key < 0) {
        throw InvalidHashOperation();
    }
    
    return hashTable[key] == T();
}
