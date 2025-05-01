#pragma once
#include <vector>

using namespace std;

class matrix 
{
private:
    int row;
    int column;
    vector<vector<int>> vec;

public:
    matrix(int row, int column);
    void insert(int value);
    matrix operator*(const matrix& other) const;
    matrix operator+(const matrix& other) const;
    matrix operator-(const matrix& other) const;
    void print_matrix() const;
};
