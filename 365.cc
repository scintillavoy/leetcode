#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canMeasureWater(int x, int y, int target) {
    vector<vector<bool>> visited(x + 1, vector<bool>(y + 1));
    queue<pair<int, int>> q;
    visited[0][0] = true;
    q.push({0, 0});
    while (!q.empty()) {
      auto [x2, y2] = q.front();
      q.pop();
      if (x2 + y2 == target) {
        return true;
      }
      if (!visited[x][y2]) {
        visited[x][y2] = true;
        q.push({x, y2});
      }
      if (!visited[x2][y]) {
        visited[x2][y] = true;
        q.push({x2, y});
      }
      if (!visited[0][y2]) {
        visited[0][y2] = true;
        q.push({0, y2});
      }
      if (!visited[x2][0]) {
        visited[x2][0] = true;
        q.push({x2, 0});
      }
      if (x2 + y2 <= y && !visited[0][x2 + y2]) {
        visited[0][x2 + y2] = true;
        q.push({0, x2 + y2});
      }
      if (x2 + y2 > y && !visited[x2 + y2 - y][y]) {
        visited[x2 + y2 - y][y] = true;
        q.push({x2 + y2 - y, y});
      }
      if (x2 + y2 <= x && !visited[x2 + y2][0]) {
        visited[x2 + y2][0] = true;
        q.push({x2 + y2, 0});
      }
      if (x2 + y2 > x && !visited[x][x2 + y2 - x]) {
        visited[x][x2 + y2 - x] = true;
        q.push({x, x2 + y2 - x});
      }
    }
    return false;
  }
};
