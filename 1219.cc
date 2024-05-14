#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int getMaximumGold(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    visited = vector<vector<bool>>(m, vector<bool>(n));
    int answer = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        answer = max(answer, backtrack(grid, i, j));
      }
    }
    return answer;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};

  int m;
  int n;
  vector<vector<bool>> visited;

  int backtrack(vector<vector<int>>& grid, int x, int y) {
    int max_value = 0;
    if (grid[x][y] == 0) {
      return max_value;
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || visited[x2][y2]) {
        continue;
      }
      max_value = max(max_value, backtrack(grid, x2, y2));
    }
    visited[x][y] = false;
    return max_value + grid[x][y];
  }
};
