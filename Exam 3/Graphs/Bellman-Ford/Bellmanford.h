#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include <vector>
#include <tuple>

class BellmanFord {
private:
    int vertices;
    std::vector<std::tuple<int, int, int>> edges;

public:
    BellmanFord(int V);
    void addEdge(int u, int v, int weight);
    std::vector<int> shortestPaths(int source, bool& hasNegativeCycle);
};

#endif
