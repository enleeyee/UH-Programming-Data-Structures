#include <iostream>
#include "Floydwarshall.h"
#include <limits>

int main() {
    // 6 vertices: a-f (mapped as 0-5)
    FloydWarshall graph(6); // a–f = 0–5

    // Mapping: a=0, b=1, c=2, d=3, e=4, f=5
    graph.addEdge(0, 1, 7);   // a–b
    graph.addEdge(0, 2, 16);  // a–c
    graph.addEdge(0, 5, 4);   // a–f
    graph.addEdge(1, 2, 11);  // b–c
    graph.addEdge(1, 3, 10);  // b–d
    graph.addEdge(2, 3, 3);   // c–d
    graph.addEdge(3, 4, 17);  // d–e
    graph.addEdge(3, 5, 5);   // d–f

    auto dist = graph.compute();

    std::cout << "All-Pairs Shortest Distances:\n";
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (dist[i][j] == std::numeric_limits<int>::max())
                std::cout << "INF ";
            else
                std::cout << dist[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
