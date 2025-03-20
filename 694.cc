#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int numDistinctIslands(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    unordered_set<string> islands;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          continue;
        }
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;
        string island;
        while (!q.empty()) {
          auto [x, y] = q.front();
          q.pop();
          for (int k = 0; k < 4; ++k) {
            int x2 = x + dx[k];
            int y2 = y + dy[k];
            if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || grid[x2][y2] == 0) {
              continue;
            }
            q.push({x2, y2});
            grid[x2][y2] = 0;
            island += to_string(i - x2) + ',' + to_string(j - y2) + '-';
          }
        }
        islands.insert(island);
      }
    }
    return islands.size();
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
