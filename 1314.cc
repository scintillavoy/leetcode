#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> prefix_sum(m + 1, vector<int>(n + 1));
    for (int i = 1; i < m + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        prefix_sum[i][j] = mat[i - 1][j - 1] + prefix_sum[i][j - 1] +
                           prefix_sum[i - 1][j] - prefix_sum[i - 1][j - 1];
      }
    }
    vector<vector<int>> block_sum(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int x1 = max(0, i - k);
        int y1 = max(0, j - k);
        int x2 = min(m - 1, i + k);
        int y2 = min(n - 1, j + k);
        block_sum[i][j] = prefix_sum[x2 + 1][y2 + 1] - prefix_sum[x2 + 1][y1] -
                          prefix_sum[x1][y2 + 1] + prefix_sum[x1][y1];
      }
    }
    return block_sum;
  }
};
