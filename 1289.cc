#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> sum = grid[0];
    for (int i = 1; i < n; ++i) {
      int min_idx1 = 0, min_idx2 = 1;
      if (sum[min_idx1] > sum[min_idx2]) {
        swap(min_idx1, min_idx2);
      }
      for (int i = 2; i < n; ++i) {
        if (sum[i] <= sum[min_idx1]) {
          min_idx2 = min_idx1;
          min_idx1 = i;
        } else if (sum[i] <= sum[min_idx2]) {
          min_idx2 = i;
        }
      }
      vector<int> next_sum(n);
      for (int j = 0; j < n; ++j) {
        next_sum[j] = grid[i][j];
        if (min_idx1 != j) {
          next_sum[j] += sum[min_idx1];
        } else {
          next_sum[j] += sum[min_idx2];
        }
      }
      sum = next_sum;
    }
    return *min_element(sum.cbegin(), sum.cend());
  }
};
