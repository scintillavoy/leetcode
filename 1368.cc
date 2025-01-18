#include <deque>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int minCost(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> costs(m, vector<int>(n, numeric_limits<int>::max()));
    deque<pair<int, int>> dq;
    costs[0][0] = 0;
    dq.push_back({0, 0});
    while (!dq.empty()) {
      auto [x, y] = dq.front();
      dq.pop_front();
      if (x == m - 1 && y == n - 1) {
        break;
      }
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        int cost = costs[x][y];
        if (i + 1 != grid[x][y]) {
          ++cost;
        }
        if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || cost >= costs[x2][y2]) {
          continue;
        }
        costs[x2][y2] = cost;
        if (i + 1 != grid[x][y]) {
          dq.push_back({x2, y2});
        } else {
          dq.push_front({x2, y2});
        }
      }
    }
    return costs[m - 1][n - 1];
  }

 private:
  const int dx[4] = {0, 0, 1, -1};
  const int dy[4] = {1, -1, 0, 0};
};
