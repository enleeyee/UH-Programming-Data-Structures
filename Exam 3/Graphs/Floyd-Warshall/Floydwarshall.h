#ifndef FLOYDWARSHALL_H
#define FLOYDWARSHALL_H

#include <vector>

class FloydWarshall {
private:
    int vertices;
    std::vector<std::vector<int>> dist;

public:
    FloydWarshall(int V);
    void addEdge(int u, int v, int weight);
    std::vector<std::vector<int>> compute();
};

#endif
