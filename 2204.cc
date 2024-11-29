#include <limits>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);
    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    vector<int> parents(n, -1);
    vector<int> nodes_in_cycle = find_nodes_in_cycle(graph, 0, parents);
    vector<int> distances_to_cycle(n, numeric_limits<int>::max());
    queue<int> q;
    for (const auto node : nodes_in_cycle) {
      distances_to_cycle[node] = 0;
      q.push(node);
    }
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (const auto adj : graph[curr]) {
        if (distances_to_cycle[adj] != numeric_limits<int>::max()) {
          continue;
        }
        distances_to_cycle[adj] = distances_to_cycle[curr] + 1;
        q.push(adj);
      }
    }
    return distances_to_cycle;
  }

 private:
  vector<int> find_nodes_in_cycle(const vector<vector<int>>& graph, int curr,
                                  vector<int>& parents) {
    for (const auto adj : graph[curr]) {
      if (parents[adj] != -1) {
        if (parents[curr] == adj) {
          continue;
        }
        vector<int> nodes_in_cycle;
        int node = curr;
        while (node != adj) {
          nodes_in_cycle.push_back(node);
          node = parents[node];
        }
        nodes_in_cycle.push_back(node);
        return nodes_in_cycle;
      }
      parents[adj] = curr;
      vector<int> result = find_nodes_in_cycle(graph, adj, parents);
      if (!result.empty()) {
        return result;
      }
    }
    return {};
  }
};
