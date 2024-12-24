#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                vector<vector<int>>& edges2) {
    int diameter1 = find_diameter(edges1);
    int diameter2 = find_diameter(edges2);
    return max(
        {diameter1, diameter2, (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1});
  }

  int find_diameter(const vector<vector<int>>& edges) {
    int n = edges.size() + 1;
    vector<vector<int>> graph(n);
    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    int farthest = 0;
    vector<bool> visited(n);
    queue<int> q;
    visited[0] = true;
    q.push(0);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      farthest = curr;
      for (const auto adj : graph[curr]) {
        if (visited[adj]) {
          continue;
        }
        visited[adj] = true;
        q.push(adj);
      }
    }
    int diameter = -1;
    visited = vector<bool>(n);
    q.push(farthest);
    while (!q.empty()) {
      ++diameter;
      for (int i = q.size(); i > 0; --i) {
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
    return diameter;
  }
};
