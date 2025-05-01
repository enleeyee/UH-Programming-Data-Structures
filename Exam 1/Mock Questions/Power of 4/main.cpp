#include <iostream>
using namespace std;

bool isPowerOfFour(int n) {
    if (n == 0) return false;
    else if (n == 1) return true;
    return n%4==0 && isPowerOfFour(n/4);
}

int main() {
    int num = 64;
    bool result = isPowerOfFour(num);
    if(result) {
        cout << num << " is a power of four." << endl;
    } else {
        cout << num << " is not a power of four." << endl;
    }

    return 0;
}
