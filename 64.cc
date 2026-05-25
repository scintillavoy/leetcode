#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> min_sum(m, vector<int>(n, numeric_limits<int>::max()));
    min_sum[0][0] = grid[0][0];
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j - 1 >= 0) {
          min_sum[i][j] = min(min_sum[i][j], min_sum[i][j - 1] + grid[i][j]);
        }
        if (i - 1 >= 0) {
          min_sum[i][j] = min(min_sum[i][j], min_sum[i - 1][j] + grid[i][j]);
        }
      }
    }
    return min_sum.back().back();
  }
};
