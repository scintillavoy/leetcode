#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> reversed_graph(n);
    vector<int> in_degrees(n);
    for (int i = 0; i < n; ++i) {
      for (const auto adj : graph[i]) {
        reversed_graph[adj].push_back(i);
        ++in_degrees[i];
      }
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (in_degrees[i] == 0) {
        q.push(i);
      }
    }
    vector<int> safe_nodes;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      safe_nodes.push_back(curr);
      for (const auto adj : reversed_graph[curr]) {
        --in_degrees[adj];
        if (in_degrees[adj] == 0) {
          q.push(adj);
        }
      }
    }
    sort(safe_nodes.begin(), safe_nodes.end());
    return safe_nodes;
  }
};
