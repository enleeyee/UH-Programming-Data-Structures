#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    Graph(int rows, int cols);
    Graph(int rows, int cols, const std::vector<std::vector<int>>& initial);
    
    void insert(int r, int c, int value);
    int orangesRotting();

private:
    int rows, cols;
    std::vector<std::vector<int>> grid;
};

#endif
