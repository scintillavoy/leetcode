#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    int result = 0;
    vector<vector<bool>> visited(n, vector<bool>(n));
    priority_queue<Cell> pq;
    visited[0][0] = true;
    pq.push({0, 0, grid[0][0]});
    while (!pq.empty()) {
      Cell curr = pq.top();
      pq.pop();
      result = max(result, curr.elevation);
      if (curr.x == n - 1 && curr.y == n - 1) {
        return result;
      }
      for (int i = 0; i < 4; ++i) {
        int x = curr.x + dx[i];
        int y = curr.y + dy[i];
        if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y]) {
          continue;
        }
        visited[x][y] = true;
        pq.push({x, y, grid[x][y]});
      }
    }
    return -1;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};

  struct Cell {
    int x;
    int y;
    int elevation;

    bool operator<(const Cell& c) const { return elevation > c.elevation; }
  };
};
