#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int getFood(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '*') {
          grid[i][j] = 'X';
          q.push({i, j});
        }
      }
    }
    int count = q.size();
    int answer = 1;
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || grid[x2][y2] == 'X') {
          continue;
        }
        if (grid[x2][y2] == '#') {
          return answer;
        }
        grid[x2][y2] = 'X';
        q.push({x2, y2});
      }
      --count;
      if (count == 0) {
        ++answer;
        count = q.size();
      }
    }
    return -1;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
