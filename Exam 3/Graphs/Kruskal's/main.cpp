#include <iostream>
#include "Kruskal.h"

int main() {
    // 6 vertices: a-f (mapped as 0-5)
    Kruskal kruskal(6);

    // Mapping: a=0, b=1, c=2, d=3, e=4, f=5
    kruskal.addEdge(0, 1, 7);   // a-b
    kruskal.addEdge(0, 2, 16);  // a-c
    kruskal.addEdge(0, 5, 4);   // a-f
    kruskal.addEdge(1, 2, 11);  // b-c
    kruskal.addEdge(1, 3, 10);  // b-d
    kruskal.addEdge(2, 3, 3);   // c-d
    kruskal.addEdge(3, 4, 17);  // d-e
    kruskal.addEdge(3, 5, 5);   // d-f

    std::vector<Edge> mst = kruskal.getMST();

    std::cout << "Edges in the MST:\n";
    for (const Edge& e : mst) {
        std::cout << char('a' + e.u) << " -- " << char('a' + e.v) << " == " << e.weight << '\n';
    }

    return 0;
}
