#include <queue>
#include <tuple>
#include <vector>
using namespace std;

#define INF 2147483647

class Solution {
 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    int m = rooms.size();
    int n = rooms[0].size();
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (rooms[i][j] == 0) {
          q.push({i, j, 0});
        }
      }
    }
    while (!q.empty()) {
      auto [x, y, d] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || rooms[x2][y2] != INF) {
          continue;
        }
        rooms[x2][y2] = d + 1;
        q.push({x2, y2, d + 1});
      }
    }
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
