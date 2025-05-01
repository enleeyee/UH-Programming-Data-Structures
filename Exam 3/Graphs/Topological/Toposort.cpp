#include "Toposort.h"
#include <stack>
#include <stdexcept>

int TopoSort::getOrAddNode(const std::string& name) {
    if (nameToIndex.count(name)) return nameToIndex[name];

    nameToIndex[name] = vertices;
    indexToName.push_back(name);
    adj.emplace_back();
    return vertices++;
}

void TopoSort::addEdge(const std::string& from, const std::string& to) {
    int u = getOrAddNode(from);
    int v = getOrAddNode(to);
    adj[u].push_back(v);
}

std::vector<std::string> TopoSort::sort() {
    std::vector<int> inDegree(vertices, 0);
    for (int u = 0; u < vertices; ++u) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    std::vector<bool> visited(vertices, false);
    std::stack<int> stack;
    std::vector<int> order;

    for (int i = 0; i < vertices; ++i) {
        if (inDegree[i] == 0 && !visited[i]) {
            stack.push(i);
            while (!stack.empty()) {
                int node = stack.top();
                stack.pop();
                if (visited[node]) continue;
                visited[node] = true;
                order.push_back(node);
                for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it) {
                    if (--inDegree[*it] == 0) {
                        stack.push(*it);
                    }
                }
            }
        }
    }

    if (order.size() != vertices) {
        throw std::runtime_error("Cycle detected — topological sort not possible.");
    }

    std::vector<std::string> result;
    for (int i : order) {
        result.push_back(indexToName[i]);
    }
    return result;
}
