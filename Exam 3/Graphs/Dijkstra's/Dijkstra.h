#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <utility>

class Dijkstra {
private:
    int vertices;
    std::vector<std::vector<std::pair<int, int>>> adjList;

public:
    Dijkstra(int V);
    void addEdge(int u, int v, int weight);
    std::vector<int> shortestPaths(int source);
};

#endif
