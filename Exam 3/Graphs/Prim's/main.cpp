#include <iostream>
#include "Prim.h"

int main() {
    // 6 vertices: a-f (mapped as 0-5)
    Prim prim(6);

    // Mapping: a=0, b=1, c=2, d=3, e=4, f=5
    prim.addEdge(0, 1, 7);   // a–b
    prim.addEdge(0, 2, 16);  // a–c
    prim.addEdge(0, 5, 4);   // a–f
    prim.addEdge(1, 2, 11);  // b–c
    prim.addEdge(1, 3, 10);  // b–d
    prim.addEdge(2, 3, 3);   // c–d
    prim.addEdge(3, 4, 17);  // d–e
    prim.addEdge(3, 5, 5);   // d–f

    auto mst = prim.getMST();

    std::cout << "Prim's MST edges:\n";
    for (auto& [u, v, w] : mst) {
        std::cout << char('a' + u) << " -- " << char('a' + v) << " == " << w << '\n';
    }

    return 0;
}
