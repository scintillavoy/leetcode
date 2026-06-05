#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if (grid[0][0] != 0) {
      return -1;
    }
    int n = grid.size();
    queue<pair<int, int>> q;
    grid[0][0] = -1;
    q.push({0, 0});
    int length = 0;
    while (!q.empty()) {
      int size = q.size();
      ++length;
      for (int i = 0; i < size; ++i) {
        auto [x, y] = q.front();
        q.pop();
        if (x == n - 1 && y == n - 1) {
          return length;
        }
        for (int j = 0; j < 8; ++j) {
          int x2 = x + dx[j];
          int y2 = y + dy[j];
          if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n || grid[x2][y2] != 0) {
            continue;
          }
          grid[x2][y2] = -1;
          q.push({x2, y2});
        }
      }
    }
    return -1;
  }

 private:
  const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
};
