#include "Kruskal.h"
#include <algorithm>

Kruskal::Kruskal(int V) {
    parent.resize(V);
    rank.resize(V, 0);
    for (int i = 0; i < V; ++i)
        parent[i] = i;
}

void Kruskal::addEdge(int u, int v, int weight) {
    edges.push_back({u, v, weight});
}

int Kruskal::find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void Kruskal::unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

std::vector<Edge> Kruskal::getMST() {
    std::vector<Edge> result;

    std::sort(edges.begin(), edges.end());

    for (const Edge& edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            result.push_back(edge);
            unionSets(edge.u, edge.v);
        }
    }

    return result;
}
