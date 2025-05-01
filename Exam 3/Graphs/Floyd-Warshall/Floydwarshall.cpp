#include "Floydwarshall.h"
#include <limits>

FloydWarshall::FloydWarshall(int V) : vertices(V) {
    dist.resize(V, std::vector<int>(V, std::numeric_limits<int>::max()));
    for (int i = 0; i < V; ++i)
        dist[i][i] = 0; 
}

void FloydWarshall::addEdge(int u, int v, int weight) {
    dist[u][v] = weight;
    dist[v][u] = weight;
}

std::vector<std::vector<int>> FloydWarshall::compute() {
    for (int k = 0; k < vertices; ++k) {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (dist[i][k] != std::numeric_limits<int>::max() &&
                    dist[k][j] != std::numeric_limits<int>::max() &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}
