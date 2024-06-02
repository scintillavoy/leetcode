#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int closedIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));
    int result = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (visited[i][j] || grid[i][j] == 1) {
          continue;
        }
        visited[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        bool closed = true;
        while (!q.empty()) {
          auto [x, y] = q.front();
          q.pop();
          for (int k = 0; k < 4; ++k) {
            int x2 = x + dx[k];
            int y2 = y + dy[k];
            if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n) {
              closed = false;
              continue;
            }
            if (visited[x2][y2] || grid[x2][y2] == 1) {
              continue;
            }
            visited[x2][y2] = true;
            q.push({x2, y2});
          }
        }
        if (closed) {
          ++result;
        }
      }
    }
    return result;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
