#include "Prim.h"
#include <climits>
#include <vector>
#include <queue>
#include <tuple>

Prim::Prim(int V) : vertices(V) {
    adjList.resize(V);
}

void Prim::addEdge(int u, int v, int weight) {
    adjList[u].emplace_back(v, weight);
    adjList[v].emplace_back(u, weight);
}

std::vector<std::tuple<int, int, int>> Prim::getMST() {
    std::vector<bool> inMST(vertices, false);
    std::vector<std::tuple<int, int, int>> mst;

    using Edge = std::pair<int, std::pair<int, int>>;
    std::priority_queue<Edge, std::vector<Edge>, std::greater<>> pq;

    pq.push({0, {0, -1}});

    while (!pq.empty()) {
        auto [weight, edge] = pq.top();
        pq.pop();
        int u = edge.first;
        int parent = edge.second;

        if (inMST[u]) continue;
        inMST[u] = true;

        if (parent != -1)
            mst.emplace_back(parent, u, weight);

        for (auto& [v, w] : adjList[u]) {
            if (!inMST[v])
                pq.push({w, {v, u}});
        }
    }

    return mst;
}
