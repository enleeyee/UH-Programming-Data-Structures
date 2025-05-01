#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    matrix matrix_a(3, 3);
    matrix_a.insert(1);
    matrix_a.insert(2);
    matrix_a.insert(3);
    matrix_a.insert(2);
    matrix_a.insert(3);
    matrix_a.insert(4);
    matrix_a.insert(4);
    matrix_a.insert(5);
    matrix_a.insert(6);

    matrix matrix_b(3, 3);
    matrix_b.insert(4);
    matrix_b.insert(3);
    matrix_b.insert(2);
    matrix_b.insert(3);
    matrix_b.insert(2);
    matrix_b.insert(1);
    matrix_b.insert(2);
    matrix_b.insert(1);
    matrix_b.insert(1);

    try {
        cout << "\nMatrix Multiplication: " << endl;
        matrix result = matrix_a * matrix_b;
        result.print_matrix();
    } catch (const invalid_argument& e) {
        cout << "Matrix Multiplication Invalid!" << endl;
    }

    try {
        cout << "\nMatrix Addition: " << endl;
        matrix result_add = matrix_a + matrix_b;
        result_add.print_matrix();
    } catch (const invalid_argument& e) {
        cout << "Matrix Addition Invalid!" << endl;
    }

    try {
        cout << "\nMatrix Subtraction: " << endl;
        matrix result_sub = matrix_a - matrix_b;
        result_sub.print_matrix();
    } catch (const invalid_argument& e) {
        cout << "Matrix Subtraction Invalid!" << endl;
    }

    return 0;
}
