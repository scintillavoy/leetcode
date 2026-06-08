#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
    vector<vector<int>> matrix(n, vector<int>(n, 1));
    for (const auto& mine : mines) {
      matrix[mine[0]][mine[1]] = 0;
    }
    // From left to right.
    for (int i = 0; i < n; ++i) {
      int running_sum = 0;
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 0) {
          running_sum = 0;
          continue;
        }
        ++running_sum;
        matrix[i][j] = running_sum;
      }
    }
    // From right to left.
    for (int i = 0; i < n; ++i) {
      int running_sum = 0;
      for (int j = n - 1; j >= 0; --j) {
        if (matrix[i][j] == 0) {
          running_sum = 0;
          continue;
        }
        ++running_sum;
        matrix[i][j] = min(matrix[i][j], running_sum);
      }
    }
    // From top to bottom.
    for (int i = 0; i < n; ++i) {
      int running_sum = 0;
      for (int j = 0; j < n; ++j) {
        if (matrix[j][i] == 0) {
          running_sum = 0;
          continue;
        }
        ++running_sum;
        matrix[j][i] = min(matrix[j][i], running_sum);
      }
    }
    // From bottom to top.
    int max_order = 0;
    for (int i = 0; i < n; ++i) {
      int running_sum = 0;
      for (int j = n - 1; j >= 0; --j) {
        if (matrix[j][i] == 0) {
          running_sum = 0;
          continue;
        }
        ++running_sum;
        matrix[j][i] = min(matrix[j][i], running_sum);
        max_order = max(max_order, matrix[j][i]);
      }
    }
    return max_order;
  }
};
