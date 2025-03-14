#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename T>
class ChainingHashing {
private:
    int size;
    vector< list<int> > table;
    int nextPrime(int n);
    bool isPrime(int n);
    int HashFunction(int key);

public:
    ChainingHashing(int initialSize);
    void Insert(int key);
    void Delete(int key);
    void Display();
    int getSize() const { return size; }
};

template <typename T>
ChainingHashing<T>::ChainingHashing(int initialSize) {
    size = nextPrime(initialSize);
    table.resize(size);
}

template <typename T>
int ChainingHashing<T>::nextPrime(int n) {
    while (!isPrime(n)) ++n;
    return n;
}

template <typename T>
bool ChainingHashing<T>::isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

template <typename T>
int ChainingHashing<T>::HashFunction(int key) {
    return key % size;
}

template <typename T>
void ChainingHashing<T>::Insert(int key) {
    int index = HashFunction(key);
    table[index].push_back(key);
}

template <typename T>
void ChainingHashing<T>::Delete(int key) {
    int index = HashFunction(key);
    auto& chain = table[index];

    for (auto it = chain.begin(); it != chain.end(); ++it) {
        if (*it == key) {
            chain.erase(it);
            cout << "Deleted: " << key << " from index " << index << endl;
            return;
        }
    }

    cout << "Key " << key << " not found!" << endl;
}

template <typename T>
void ChainingHashing<T>::Display() {
    cout << "***** Hash Table *****" << endl;
    for (int i = 0; i < size; ++i) {
        cout << i;
        if (!table[i].empty()) {
            cout << " --> ";
            for (int value : table[i]) {
                cout << value << " ";
            }
        }
        cout << endl;
    }
    cout << "**********************" << endl;
}
