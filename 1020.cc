#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
      if (grid[0][i] == 1) {
        q.push({0, i});
        grid[0][i] = 0;
      }
      if (grid[m - 1][i] == 1) {
        q.push({m - 1, i});
        grid[m - 1][i] = 0;
      }
    }
    for (int i = 1; i < m - 1; ++i) {
      if (grid[i][0] == 1) {
        q.push({i, 0});
        grid[i][0] = 0;
      }
      if (grid[i][n - 1] == 1) {
        q.push({i, n - 1});
        grid[i][n - 1] = 0;
      }
    }
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || grid[x2][y2] == 0) {
          continue;
        }
        q.push({x2, y2});
        grid[x2][y2] = 0;
      }
    }
    int num_of_enclaves = 0;
    for (const auto& row : grid) {
      for (const auto cell : row) {
        if (cell == 1) {
          ++num_of_enclaves;
        }
      }
    }
    return num_of_enclaves;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
