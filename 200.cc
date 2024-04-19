#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int answer = 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (visited[i][j] || grid[i][j] == '0') {
          continue;
        }
        ++answer;
        queue<pair<int, int>> q;
        visited[i][j] = true;
        q.push({i, j});
        while (!q.empty()) {
          auto [x, y] = q.front();
          q.pop();
          for (int k = 0; k < 4; ++k) {
            int x2 = x + dx[k];
            int y2 = y + dy[k];
            if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || visited[x2][y2] ||
                grid[x2][y2] == '0') {
              continue;
            }
            visited[x2][y2] = true;
            q.push({x2, y2});
          }
        }
      }
    }
    return answer;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
