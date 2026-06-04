#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int numOfMinutes(int n, int headID, vector<int>& manager,
                   vector<int>& informTime) {
    vector<vector<int>> graph(n);
    for (int i = 0; i < manager.size(); ++i) {
      if (manager[i] == -1) {
        continue;
      }
      graph[manager[i]].push_back(i);
    }
    queue<pair<int, int>> q;  // (ID, cumulative inform time) pairs
    q.push({headID, 0});
    int time_needed = 0;
    while (!q.empty()) {
      auto [curr, time] = q.front();
      q.pop();
      time_needed = max(time_needed, time);
      for (const auto adj : graph[curr]) {
        q.push({adj, time + informTime[curr]});
      }
    }
    return time_needed;
  }
};
