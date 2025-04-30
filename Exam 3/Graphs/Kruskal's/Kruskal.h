#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>

struct Edge {
    int u, v;
    int weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Kruskal {
private:
    std::vector<Edge> edges;
    std::vector<int> parent, rank;

    int find(int u);
    void unionSets(int u, int v);

public:
    Kruskal(int V);
    void addEdge(int u, int v, int weight);
    std::vector<Edge> getMST();
};

#endif
