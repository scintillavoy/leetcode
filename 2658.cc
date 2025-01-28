#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int findMaxFish(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int max_num_of_fish = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          continue;
        }
        queue<pair<int, int>> q;
        q.push({i, j});
        int num_of_fish = 0;
        while (!q.empty()) {
          auto [x, y] = q.front();
          q.pop();
          num_of_fish += grid[x][y];
          grid[x][y] = 0;
          for (int k = 0; k < 4; ++k) {
            int x2 = x + dx[k];
            int y2 = y + dy[k];
            if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || grid[x2][y2] == 0) {
              continue;
            }
            q.push({x2, y2});
          }
        }
        max_num_of_fish = max(max_num_of_fish, num_of_fish);
      }
    }
    return max_num_of_fish;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
