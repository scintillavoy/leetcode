#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max_area = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          continue;
        }
        queue<pair<int, int>> q;
        grid[i][j] = 0;
        q.push({i, j});
        int area = 0;
        while (!q.empty()) {
          auto [x, y] = q.front();
          q.pop();
          ++area;
          for (int k = 0; k < 4; ++k) {
            int x2 = x + dx[k];
            int y2 = y + dy[k];
            if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || grid[x2][y2] == 0) {
              continue;
            }
            grid[x2][y2] = 0;
            q.push({x2, y2});
          }
        }
        max_area = max(max_area, area);
      }
    }
    return max_area;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
