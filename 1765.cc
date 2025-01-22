#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int m = isWater.size();
    int n = isWater[0].size();
    vector<vector<int>> height(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (isWater[i][j] == 1) {
          height[i][j] = 0;
          q.push({i, j});
        }
      }
    }
    while (!q.empty()) {
      for (int i = q.size(); i > 0; --i) {
        auto [x, y] = q.front();
        q.pop();
        for (int j = 0; j < 4; ++j) {
          int x2 = x + dx[j];
          int y2 = y + dy[j];
          if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || height[x2][y2] != -1) {
            continue;
          }
          height[x2][y2] = height[x][y] + 1;
          q.push({x2, y2});
        }
      }
    }
    return height;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
