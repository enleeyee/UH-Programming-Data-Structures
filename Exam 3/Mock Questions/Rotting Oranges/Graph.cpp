#include "Graph.h"
#include <queue>
#include <stdexcept>
using namespace std;

Graph::Graph(int r, int c) : rows(r), cols(c) {
    grid.resize(rows, vector<int>(cols, 0));
}

Graph::Graph(int r, int c, const vector<vector<int>>& initial)
    : rows(r), cols(c), grid(initial) {}

void Graph::insert(int r, int c, int value) {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        throw out_of_range("Insert position out of grid bounds");
    grid[r][c] = value;
}

int Graph::orangesRotting() {
    queue<pair<int, int>> q;
    int fresh = 0;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == 2) q.push({r, c});
            else if (grid[r][c] == 1) ++fresh;
        }
    }

    if (fresh == 0) return 0;

    int minutes = -1;
    vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    while (!q.empty()) {
        int size = q.size();
        ++minutes;

        for (int i = 0; i < size; ++i) {
            auto [r, c] = q.front(); q.pop();

            for (auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    --fresh;
                }
            }
        }
    }

    return fresh == 0 ? minutes : -1;
}
