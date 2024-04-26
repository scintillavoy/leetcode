#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> sum = matrix[0];
    for (int i = 1; i < n; ++i) {
      vector<int> next_sum(m);
      for (int j = 0; j < m; ++j) {
        int min_value = sum[j];
        if (j - 1 >= 0) {
          min_value = min(min_value, sum[j - 1]);
        }
        if (j + 1 < m) {
          min_value = min(min_value, sum[j + 1]);
        }
        next_sum[j] = min_value + matrix[i][j];
      }
      sum = next_sum;
    }
    return *min_element(sum.cbegin(), sum.cend());
  }
};
