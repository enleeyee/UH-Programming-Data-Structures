#include <iostream>
#include "LinearHashing.h"
using namespace std;

int main() {
    LinearHashing<int> lh(4);

    lh.Insert(3, 100);
    lh.Insert(5, 200);
    lh.Insert(7, 300);
    lh.Insert(1, 400);

    cout << "Value at key 3: " << lh.Search(3) << endl;
    cout << "Value at key 5: " << lh.Search(5) << endl;

    lh.Delete(5);
    
    try {
        cout << "Value at key 5 after deletion: " << lh.Search(5) << endl;
    } catch (const InvalidHashOperation&) {
        cout << "Key 5 has been deleted." << endl;
    }

    cout << "Is key 5 empty? " << (lh.IsEmpty(5) ? "Yes" : "No") << endl;
    cout << "Is key 7 empty? " << (lh.IsEmpty(7) ? "Yes" : "No") << endl;

    return 0;
}
