#include <vector>
using namespace std;

class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m));
    int answer = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 0) {
          continue;
        }
        answer += 4;
        for (int k = 0; k < 4; ++k) {
          int x2 = i + dx[k];
          int y2 = j + dy[k];
          if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) {
            continue;
          }
          if (grid[x2][y2] == 1) {
            --answer;
          }
        }
      }
    }
    return answer;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {1, -1, 0, 0};
};
