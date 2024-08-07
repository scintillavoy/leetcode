#include <algorithm>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
 public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> distances(
        m,
        vector<vector<int>>(n, vector<int>(k + 1, numeric_limits<int>::max())));
    distances[0][0][0] = 0;
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    while (!q.empty()) {
      auto [x, y, remove_count] = q.front();
      q.pop();
      if (x == m - 1 && y == n - 1) {
        return distances[x][y][remove_count];
      }
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n ||
            remove_count + grid[x2][y2] > k ||
            distances[x2][y2][remove_count + grid[x2][y2]] !=
                numeric_limits<int>::max()) {
          continue;
        }
        distances[x2][y2][remove_count + grid[x2][y2]] =
            distances[x][y][remove_count] + 1;
        q.push({x2, y2, remove_count + grid[x2][y2]});
      }
    }
    return -1;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
