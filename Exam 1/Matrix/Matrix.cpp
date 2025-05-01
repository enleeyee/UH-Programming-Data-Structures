#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

matrix::matrix(int row, int column) : row(row), column(column) {
    vec.resize(row, vector<int>(column, 0));
}

void matrix::insert(int value) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (vec[i][j] == 0) {
                vec[i][j] = value;
                return;
            }
        }
    }
}

matrix matrix::operator*(const matrix& other) const {
    if (column != other.row) {
        throw invalid_argument("Matrix multiplication invalid!");
    }

    matrix result(row, other.column);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < other.column; ++j) {
            int cell_value = 0;
            for (int k = 0; k < column; ++k) {
                cell_value += vec[i][k] * other.vec[k][j];
            }
            result.vec[i][j] = cell_value;
        }
    }

    return result;
}

matrix matrix::operator+(const matrix& other) const {
    if (row != other.row || column != other.column) {
        throw invalid_argument("Matrix addition invalid: dimensions do not match.");
    }

    matrix result(row, column);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            result.vec[i][j] = vec[i][j] + other.vec[i][j];
        }
    }
    return result;
}

matrix matrix::operator-(const matrix& other) const {
    if (row != other.row || column != other.column) {
        throw invalid_argument("Matrix subtraction invalid: dimensions do not match.");
    }

    matrix result(row, column);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            result.vec[i][j] = vec[i][j] - other.vec[i][j];
        }
    }
    return result;
}

void matrix::print_matrix() const {
    vector<int> col_widths(column, 0);
    int size = 0;
    for (int j = 0; j < column; ++j) {
        for (int i = 0; i < row; ++i) {
            size = max(size, 
                static_cast<int>(to_string(vec[i][j]).length()));
        }
    }

    for (int i = 0; i < row; ++i) {
        cout << "| ";
        for (int j = 0; j < column; ++j) {
            cout << setw(size) << vec[i][j];
            if (j < column - 1) cout << " | ";
        }
        cout << " |" << endl;
    }
}
