#include <queue>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumMinimumPath(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));
    priority_queue<tuple<int, int, int>> pq;
    visited[0][0] = true;
    pq.push({grid[0][0], 0, 0});
    int answer = grid[0][0];
    while (!pq.empty()) {
      auto [value, x, y] = pq.top();
      pq.pop();
      answer = min(answer, value);
      if (x == m - 1 && y == n - 1) {
        break;
      }
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || visited[x2][y2]) {
          continue;
        }
        visited[x2][y2] = true;
        pq.push({grid[x2][y2], x2, y2});
      }
    }
    return answer;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
