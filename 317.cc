#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int shortestDistance(vector<vector<int>>& grid) {
    int min_distance = numeric_limits<int>::max();
    int m = grid.size();
    int n = grid[0].size();
    int num_of_buildings = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          ++num_of_buildings;
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] != 0) {
          continue;
        }
        int distance = 0;
        int num_of_iterations = 0;
        int num_of_visited_buildings = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int, int>> q;
        visited[i][j] = true;
        q.push({i, j});
        while (!q.empty()) {
          ++num_of_iterations;
          for (int k = q.size(); k > 0; --k) {
            auto [x, y] = q.front();
            q.pop();
            for (int l = 0; l < 4; ++l) {
              int x2 = x + dx[l];
              int y2 = y + dy[l];
              if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || visited[x2][y2]) {
                continue;
              }
              visited[x2][y2] = true;
              if (grid[x2][y2] == 0) {
                q.push({x2, y2});
              } else if (grid[x2][y2] == 1) {
                distance += num_of_iterations;
                ++num_of_visited_buildings;
              }
            }
          }
        }
        if (num_of_visited_buildings == num_of_buildings) {
          min_distance = min(min_distance, distance);
        }
      }
    }
    return min_distance == numeric_limits<int>::max() ? -1 : min_distance;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
