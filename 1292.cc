#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> prefix_sum(m + 1, vector<int>(n + 1));
    for (int i = 1; i < m + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] -
                           prefix_sum[i - 1][j - 1] + mat[i - 1][j - 1];
      }
    }
    int low = 0;
    int high = min(m, n);
    while (low <= high) {
      int mid = low + (high - low) / 2;
      bool possible = false;
      for (int i = 0; i + mid - 1 < m; ++i) {
        for (int j = 0; j + mid - 1 < n; ++j) {
          if (prefix_sum[i + mid][j + mid] - prefix_sum[i + mid][j] -
                  prefix_sum[i][j + mid] + prefix_sum[i][j] <=
              threshold) {
            possible = true;
          }
        }
      }
      if (!possible) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return low - 1;
  }
};
