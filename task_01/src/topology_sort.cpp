#include "topology_sort.hpp"
#include <algorithm>

namespace {

void dfs(int node, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<int>& toposort) {
    if (visited[node]) return;
    visited[node] = true;
    for (int neighbour : adj[node]) {
        dfs(neighbour, adj, visited, toposort);
    }
    toposort.push_back(node);
}

}  // namespace

std::vector<int> TopologySort(const std::vector<std::vector<int>>& adj) {
    int n = adj.size();
    std::vector<bool> visited(n, false);
    std::vector<int> toposort;

    for (int node = 0; node < n; ++node) {
        if (!visited[node]) {
            dfs(node, adj, visited, toposort);
        }
    }

    std::reverse(toposort.begin(), toposort.end());
    return toposort;
}