#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 2) {
          q.push({i, j});
        }
      }
    }
    int result = -1;
    while (!q.empty()) {
      ++result;
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        auto [x, y] = q.front();
        q.pop();
        for (int j = 0; j < 4; ++j) {
          int x2 = x + dx[j];
          int y2 = y + dy[j];
          if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || grid[x2][y2] != 1) {
            continue;
          }
          grid[x2][y2] = 2;
          q.push({x2, y2});
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          return -1;
        }
      }
    }
    return max(0, result);
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
