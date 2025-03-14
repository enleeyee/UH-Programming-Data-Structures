#include <iostream>
#include <stdexcept>
using namespace std;

class InvalidHashOperation {};

template <typename T>
class LinearHashing {
public:
    LinearHashing(int initialCapacity);
    ~LinearHashing();
    
    void Insert(int key, T value);
    T Search(int key); 
    void Delete(int key);
    bool IsEmpty(int key);
    
private:
    int capacity;
    int size;
    T* hashTable;
    int* keys;
    int HashFunction(int key);
    void Resize();
};

template <typename T>
LinearHashing<T>::LinearHashing(int initialCapacity) {
    capacity = initialCapacity;
    size = 0;
    hashTable = new T[capacity];
    keys = new int[capacity];
    for (int i = 0; i < capacity; i++) {
        hashTable[i] = T();
        keys[i] = -1;
    }
}

template <typename T>
LinearHashing<T>::~LinearHashing() {
    delete[] hashTable;
    delete[] keys;
}

template <typename T>
int LinearHashing<T>::HashFunction(int key) {
    return key % capacity;
}

template <typename T>
void LinearHashing<T>::Insert(int key, T value) {
    if (size >= capacity / 2) {
        Resize();
    }

    int index = HashFunction(key);
    int originalIndex = index;

    while (keys[index] != -1) {
        if (keys[index] == key) {
            hashTable[index] = value;
            return;
        }

        index = (index + 1) % capacity;
        if (index == originalIndex) {
            throw InvalidHashOperation();
        }
    }

    hashTable[index] = value;
    keys[index] = key;
    size++;
}

template <typename T>
T LinearHashing<T>::Search(int key) {
    int index = HashFunction(key);
    int originalIndex = index;

    while (keys[index] != -1) {
        if (keys[index] == key) {
            return hashTable[index];
        }

        index = (index + 1) % capacity;
        if (index == originalIndex) {
            throw InvalidHashOperation();
        }
    }

    throw InvalidHashOperation();
}

template <typename T>
void LinearHashing<T>::Delete(int key) {
    int index = HashFunction(key);
    int originalIndex = index;

    while (keys[index] != -1) {
        if (keys[index] == key) {
            hashTable[index] = T();
            keys[index] = -1;
            size--;
            return;
        }

        index = (index + 1) % capacity;
        if (index == originalIndex) {
            throw InvalidHashOperation();
        }
    }

    throw InvalidHashOperation();
}

template <typename T>
bool LinearHashing<T>::IsEmpty(int key) {
    int index = HashFunction(key);
    return keys[index] == -1;
}

template <typename T>
void LinearHashing<T>::Resize() {
    int oldCapacity = capacity;
    capacity *= 2;
    T* oldTable = hashTable;
    int* oldKeys = keys;
    
    hashTable = new T[capacity];
    keys = new int[capacity];
    for (int i = 0; i < capacity; i++) {
        hashTable[i] = T();
        keys[i] = -1;
    }

    for (int i = 0; i < oldCapacity; i++) {
        if (oldKeys[i] != -1) {
            Insert(oldKeys[i], oldTable[i]);
        }
    }

    delete[] oldTable;
    delete[] oldKeys;
}
