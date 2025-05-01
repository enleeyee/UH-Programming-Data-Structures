#include <iostream>
#include "Bellmanford.h"

int main() {
    // 6 vertices: a-f (mapped as 0-5)
    BellmanFord graph(6);

    // Mapping: a=0, b=1, c=2, d=3, e=4, f=5
    graph.addEdge(0, 1, 7);   // a–b
    graph.addEdge(0, 2, 16);  // a–c
    graph.addEdge(0, 5, 4);   // a–f
    graph.addEdge(1, 2, 11);  // b–c
    graph.addEdge(1, 3, 10);  // b–d
    graph.addEdge(2, 3, 3);   // c–d
    graph.addEdge(3, 4, 17);  // d–e
    graph.addEdge(3, 5, 5);   // d–f

    int source = 0; // from node 'a'
    bool hasNegativeCycle = false;
    auto dist = graph.shortestPaths(source, hasNegativeCycle);

    if (hasNegativeCycle) {
        std::cout << "Negative weight cycle detected.\n";
    } else {
        std::cout << "Shortest distances from a:\n";
        for (int i = 0; i < dist.size(); ++i) {
            std::cout << "a -> " << static_cast<char>('a' + i) << " = " << dist[i] << '\n';
        }
    }

    return 0;
}
