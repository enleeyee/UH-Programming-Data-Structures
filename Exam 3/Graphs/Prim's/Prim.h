#ifndef PRIM_H
#define PRIM_H

#include <vector>
#include <queue>
#include <utility>

class Prim {
private:
    int vertices;
    std::vector<std::vector<std::pair<int, int>>> adjList;

public:
    Prim(int V);
    void addEdge(int u, int v, int weight);
    std::vector<std::tuple<int, int, int>> getMST();
};

#endif
