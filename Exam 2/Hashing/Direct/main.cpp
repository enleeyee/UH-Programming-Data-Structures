#include <iostream>
#include "DirectHashing.h"
using namespace std;

int main() {
    DirectHashing<int> dh(10);
    
    dh.Insert(3, 100);
    dh.Insert(5, 200);
    dh.Insert(7, 300);
    
    cout << "Value at key 3: " << dh.Search(3) << endl;
    cout << "Value at key 5: " << dh.Search(5) << endl;
    
    dh.Delete(5);
    
    try {
        cout << "Value at key 5 after deletion: " << dh.Search(5) << endl;
    } catch (const InvalidHashOperation&) {
        cout << "Key 5 has been deleted." << endl;
    }
    
    cout << "Is key 5 empty? " << (dh.IsEmpty(5) ? "Yes" : "No") << endl;
    cout << "Is key 7 empty? " << (dh.IsEmpty(7) ? "Yes" : "No") << endl;
    
    return 0;
}
