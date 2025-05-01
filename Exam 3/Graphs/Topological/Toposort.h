#ifndef TOPOSORT_H
#define TOPOSORT_H

#include <vector>
#include <unordered_map>
#include <string>

class TopoSort {
private:
    int vertices = 0;
    std::vector<std::vector<int>> adj;
    std::unordered_map<std::string, int> nameToIndex;
    std::vector<std::string> indexToName;

    int getOrAddNode(const std::string& name);

public:
    void addEdge(const std::string& from, const std::string& to);
    std::vector<std::string> sort();
};

#endif
