#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    vector<vector<int>> graph(n + 1);
    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    vector<vector<int>> distances(
        2, vector<int>(n + 1, numeric_limits<int>::max()));
    distances[0][1] = 0;
    queue<pair<int, int>> q;
    q.push({1, 0});
    int d = 1;
    while (!q.empty()) {
      for (int i = q.size(); i > 0; --i) {
        auto [curr, order] = q.front();
        q.pop();
        for (const auto adj : graph[curr]) {
          int next_order = order;
          while (next_order < distances.size() &&
                 distances[next_order][adj] != numeric_limits<int>::max()) {
            ++next_order;
          }
          if (next_order < distances.size() &&
              (next_order == 0 || distances[next_order - 1][adj] < d)) {
            distances[next_order][adj] = d;
            q.push({adj, next_order});
          }
        }
      }
      ++d;
    }
    int total_time = 0;
    for (int i = distances.back().back(); i > 0; --i) {
      if ((total_time / change) % 2 == 1) {
        total_time = change * (total_time / change + 1);
      }
      total_time += time;
    }
    return total_time;
  }
};
