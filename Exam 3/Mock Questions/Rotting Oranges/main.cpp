#include <iostream>
#include "Graph.h"

int main() {
    Graph g(3, 3);

    g.insert(0, 0, 2);
    g.insert(0, 1, 1);
    g.insert(0, 2, 1);
    g.insert(1, 0, 1);
    g.insert(1, 1, 1);
    g.insert(1, 2, 0);
    g.insert(2, 1, 1);
    g.insert(2, 2, 1);

    int result = g.orangesRotting();
    std::cout << "Minutes to rot all oranges: " << result << std::endl;

    return 0;
}
