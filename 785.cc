#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n);
    for (int i = 0; i < n; ++i) {
      if (color[i] != 0) {
        continue;
      }
      color[i] = 1;
      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (const auto& adj : graph[curr]) {
          if (color[adj] == 0) {
            color[adj] = -1 * color[curr];
            q.push(adj);
          } else if (color[adj] == color[curr]) {
            return false;
          }
        }
      }
    }
    return true;
  }
};
