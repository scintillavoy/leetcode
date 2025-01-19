#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    int m = heightMap.size();
    int n = heightMap[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));
    priority_queue<Cell> boundary;
    for (int i = 0; i < m; ++i) {
      boundary.push({heightMap[i][0], i, 0});
      boundary.push({heightMap[i][n - 1], i, n - 1});
      visited[i][0] = true;
      visited[i][n - 1] = true;
    }
    for (int i = 1; i < n - 1; ++i) {
      boundary.push({heightMap[0][i], 0, i});
      boundary.push({heightMap[m - 1][i], m - 1, i});
      visited[0][i] = true;
      visited[m - 1][i] = true;
    }
    int total_water_volume = 0;
    while (!boundary.empty()) {
      auto [height, x, y] = boundary.top();
      boundary.pop();
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || visited[x2][y2]) {
          continue;
        }
        if (heightMap[x2][y2] < height) {
          total_water_volume += height - heightMap[x2][y2];
        }
        boundary.push({max(height, heightMap[x2][y2]), x2, y2});
        visited[x2][y2] = true;
      }
    }
    return total_water_volume;
  }

 private:
  struct Cell {
    int height;
    int x;
    int y;

    bool operator<(const Cell& other) const { return height >= other.height; }
  };

  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
