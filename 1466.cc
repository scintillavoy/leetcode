#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<pair<int, bool>>> graph(n);
    for (const auto& connection : connections) {
      graph[connection[0]].push_back({connection[1], false});
      graph[connection[1]].push_back({connection[0], true});
    }
    int result = 0;
    vector<bool> visited(n);
    queue<int> q;
    visited[0] = true;
    q.push(0);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (const auto [adj, reversed] : graph[curr]) {
        if (visited[adj]) {
          continue;
        }
        if (!reversed) {
          ++result;
        }
        visited[adj] = true;
        q.push(adj);
      }
    }
    return result;
  }
};
