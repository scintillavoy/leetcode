#include <vector>
using namespace std;

class Solution {
 public:
  int matrixScore(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; ++i) {
      if (grid[i][0] == 0) {
        for (int j = 0; j < n; ++j) {
          grid[i][j] ^= 1;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      int count = 0;
      for (int j = 0; j < m; ++j) {
        if (grid[j][i] == 0) {
          ++count;
        }
      }
      if (count > m / 2) {
        for (int j = 0; j < m; ++j) {
          grid[j][i] ^= 1;
        }
      }
    }
    int score = 0;
    for (int i = 0; i < m; ++i) {
      int num = 0;
      for (int j = 0; j < n; ++j) {
        num = (num << 1) + grid[i][j];
      }
      score += num;
    }
    return score;
  }
};
