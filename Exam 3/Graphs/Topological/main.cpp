#include <iostream>
#include "Toposort.h"

int main() {
    TopoSort graph;

    graph.addEdge("b", "e");
    graph.addEdge("b", "g");
    graph.addEdge("e", "g");
    graph.addEdge("g", "a");
    graph.addEdge("a", "f");
    graph.addEdge("f", "h");
    graph.addEdge("h", "c");
    graph.addEdge("c", "d");
    graph.addEdge("b", "f");
    graph.addEdge("b", "h");
    graph.addEdge("b", "c");

    auto order = graph.sort();

    std::cout << "Topological Sort Order:\n";
    for (const auto& name : order) {
        std::cout << name << ' ';
    }
    std::cout << std::endl;

    return 0;
}
