#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    graph = vector<vector<int>>(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        long long dx = abs(bombs[i][0] - bombs[j][0]);
        long long dy = abs(bombs[i][1] - bombs[j][1]);
        double distance = sqrt(dx * dx + dy * dy);
        if (distance <= bombs[i][2]) {
          graph[i].push_back(j);
        }
        if (distance <= bombs[j][2]) {
          graph[j].push_back(i);
        }
      }
    }
    int answer = 1;
    for (int i = 0; i < n; ++i) {
      visited = vector<bool>(n);
      answer = max(answer, dfs(i));
    }
    return answer;
  }

 private:
  vector<vector<int>> graph;
  vector<bool> visited;

  int dfs(int curr) {
    visited[curr] = true;
    int count = 1;
    for (const auto& adj : graph[curr]) {
      if (!visited[adj]) {
        count += dfs(adj);
      }
    }
    return count;
  }
};
