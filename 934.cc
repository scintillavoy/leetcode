#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int shortestBridge(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));
    queue<pair<int, int>> q, q2;
    pair<int, int> land = find_first(1, grid);
    visited[land.first][land.second] = true;
    q.push(land);
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || visited[x2][y2]) {
          continue;
        }
        visited[x2][y2] = true;
        if (grid[x2][y2] == 1) {
          q.push({x2, y2});
        } else {
          q2.push({x2, y2});
        }
      }
    }
    int result = 0;
    while (!q2.empty()) {
      ++result;
      for (int i = q2.size(); i > 0; --i) {
        auto [x, y] = q2.front();
        q2.pop();
        for (int j = 0; j < 4; ++j) {
          int x2 = x + dx[j];
          int y2 = y + dy[j];
          if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || visited[x2][y2]) {
            continue;
          }
          visited[x2][y2] = true;
          if (grid[x2][y2] == 1) {
            return result;
          } else {
            q2.push({x2, y2});
          }
        }
      }
    }
    return -1;
  }

 private:
  int m;
  int n;

  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};

  pair<int, int> find_first(int value, const vector<vector<int>>& grid) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          return {i, j};
        }
      }
    }
    return {-1, -1};
  }
};
