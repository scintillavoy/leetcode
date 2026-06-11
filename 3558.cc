#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int assignEdgeWeights(vector<vector<int>>& edges) {
    int n = edges.size() + 1;
    vector<vector<int>> graph(n);
    for (const auto& edge : edges) {
      graph[edge[0] - 1].push_back(edge[1] - 1);
      graph[edge[1] - 1].push_back(edge[0] - 1);
    }
    vector<bool> visited(n);
    queue<int> q;
    visited[0] = true;
    q.push(0);
    int max_depth = -1;
    while (!q.empty()) {
      ++max_depth;
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        int curr = q.front();
        q.pop();
        for (const auto adj : graph[curr]) {
          if (visited[adj]) {
            continue;
          }
          visited[adj] = true;
          q.push(adj);
        }
      }
    }
    int result = 1;
    for (int i = 0; i < max_depth - 1; ++i) {
      result = result * 2 % 1'000'000'007;
    }
    return result;
  }
};
