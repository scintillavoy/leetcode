#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumSafenessFactor(vector<vector<int>>& grid) {
    int n = grid.size();

    // Calculate safeness for each cell, which is the minimum Manhattan distance
    // from any thief cell.
    vector<vector<int>> safeness(n, vector<int>(n, numeric_limits<int>::max()));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          safeness[i][j] = 0;
          q.push({i, j});
        }
      }
    }
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n ||
            safeness[x2][y2] != numeric_limits<int>::max()) {
          continue;
        }
        safeness[x2][y2] = safeness[x][y] + 1;
        q.push({x2, y2});
      }
    }

    // Find the maximum safeness factor of all paths.
    int left = 0, right = 800;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      bool valid = false;
      vector<vector<bool>> visited(n, vector<bool>(n));
      queue<pair<int, int>> q2;
      if (safeness[0][0] >= mid) {
        visited[0][0] = true;
        q2.push({0, 0});
      }
      while (!q2.empty()) {
        auto [x, y] = q2.front();
        q2.pop();
        if (x == n - 1 && y == n - 1) {
          valid = true;
          break;
        }
        for (int i = 0; i < 4; ++i) {
          int x2 = x + dx[i];
          int y2 = y + dy[i];
          if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n || visited[x2][y2] ||
              safeness[x2][y2] < mid) {
            continue;
          }
          visited[x2][y2] = true;
          q2.push({x2, y2});
        }
      }
      if (!valid) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left - 1;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
