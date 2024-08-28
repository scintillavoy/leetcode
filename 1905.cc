#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int m = grid2.size();
    int n = grid2[0].size();
    int count = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid2[i][j] == 0) {
          continue;
        }
        bool valid = grid1[i][j] == 1;
        queue<pair<int, int>> q;
        grid2[i][j] = 0;
        q.push({i, j});
        while (!q.empty()) {
          auto [x, y] = q.front();
          q.pop();
          for (int k = 0; k < 4; ++k) {
            int x2 = x + dx[k];
            int y2 = y + dy[k];
            if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || grid2[x2][y2] == 0) {
              continue;
            }
            if (grid1[x2][y2] == 0) {
              valid = false;
            }
            grid2[x2][y2] = 0;
            q.push({x2, y2});
          }
        }
        if (valid) {
          ++count;
        }
      }
    }
    return count;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
