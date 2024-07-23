#include <deque>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumObstacles(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));
    deque<tuple<int, int, int>> q;
    visited[0][0] = true;
    q.push_back({0, 0, grid[0][0]});
    while (!q.empty()) {
      auto [x, y, count] = q.front();
      q.pop_front();
      if (x == m - 1 && y == n - 1) {
        return count;
      }
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || visited[x2][y2]) {
          continue;
        }
        visited[x2][y2] = true;
        if (grid[x2][y2] == 0) {
          q.push_front({x2, y2, count});
        } else {
          q.push_back({x2, y2, count + 1});
        }
      }
    }
    return -1;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
