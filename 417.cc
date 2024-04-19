#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    m = heights.size();
    n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n));
    vector<vector<bool>> atlantic(m, vector<bool>(n));
    for (int i = 0; i < m; ++i) {
      dfs(i, 0, pacific, heights);
      dfs(i, n - 1, atlantic, heights);
    }
    for (int i = 0; i < n; ++i) {
      dfs(0, i, pacific, heights);
      dfs(m - 1, i, atlantic, heights);
    }
    vector<vector<int>> result;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (pacific[i][j] && atlantic[i][j]) {
          result.push_back({i, j});
        }
      }
    }
    return result;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};

  int m;
  int n;

  void dfs(int x, int y, vector<vector<bool>>& visited,
           vector<vector<int>>& heights) {
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (x2 < 0 || y2 < 0 || x2 >= m || y2 >= n || visited[x2][y2] ||
          heights[x][y] > heights[x2][y2]) {
        continue;
      }
      dfs(x2, y2, visited, heights);
    }
  }
};
