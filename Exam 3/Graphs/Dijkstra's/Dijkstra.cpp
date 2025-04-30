#include "Dijkstra.h"
#include <queue>
#include <limits>

Dijkstra::Dijkstra(int V) : vertices(V) {
    adjList.resize(V);
}

void Dijkstra::addEdge(int u, int v, int weight) {
    adjList[u].emplace_back(v, weight);
    adjList[v].emplace_back(u, weight);
}

std::vector<int> Dijkstra::shortestPaths(int source) {
    std::vector<int> dist(vertices, std::numeric_limits<int>::max());
    dist[source] = 0;

    using Pair = std::pair<int, int>;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<>> pq;

    pq.emplace(0, source);

    while (!pq.empty()) {
        auto [currDist, u] = pq.top();
        pq.pop();

        if (currDist > dist[u]) continue;

        for (auto [v, weight] : adjList[u]) {
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}
