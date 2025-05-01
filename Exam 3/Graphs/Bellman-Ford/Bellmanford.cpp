#include "Bellmanford.h"
#include <limits>

BellmanFord::BellmanFord(int V) : vertices(V) {}

void BellmanFord::addEdge(int u, int v, int weight) {
    edges.emplace_back(u, v, weight);
}

std::vector<int> BellmanFord::shortestPaths(int source, bool& hasNegativeCycle) {
    std::vector<int> dist(vertices, std::numeric_limits<int>::max());
    dist[source] = 0;
    hasNegativeCycle = false;

    for (int i = 0; i < vertices - 1; ++i) {
        for (const auto& [u, v, w] : edges) {
            if (dist[u] != std::numeric_limits<int>::max() && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (const auto& [u, v, w] : edges) {
        if (dist[u] != std::numeric_limits<int>::max() && dist[u] + w < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    return dist;
}
