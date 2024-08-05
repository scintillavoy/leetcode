#include <algorithm>
#include <cmath>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    parents = vector<vector<pair<int, int>>>(m, vector<pair<int, int>>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        parents[i][j] = {i, j};
      }
    }
    ranks = vector<vector<int>>(m, vector<int>(n));
    int min_effort = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
      auto [effort, x, y] = pq.top();
      pq.pop();
      union_set({0, 0}, {x, y});
      min_effort = max(min_effort, effort);
      if (x == m - 1 && y == n - 1) {
        break;
      }
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n ||
            find_set({x2, y2}) == find_set({0, 0})) {
          continue;
        }
        pq.push({abs(heights[x][y] - heights[x2][y2]), x2, y2});
      }
    }
    return min_effort;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};

  vector<vector<pair<int, int>>> parents;
  vector<vector<int>> ranks;

  pair<int, int> find_set(pair<int, int> x) {
    if (parents[x.first][x.second] != x) {
      parents[x.first][x.second] = find_set(parents[x.first][x.second]);
    }
    return parents[x.first][x.second];
  }

  void union_set(pair<int, int> x, pair<int, int> y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) {
      return;
    }
    if (ranks[x.first][x.second] > ranks[y.first][y.second]) {
      swap(x, y);
    } else if (ranks[x.first][x.second] == ranks[y.first][y.second]) {
      ++ranks[y.first][y.second];
    }
    parents[x.first][x.second] = y;
  }
};
