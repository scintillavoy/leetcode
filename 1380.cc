#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row_min(m, numeric_limits<int>::max());
    vector<int> col_max(n, numeric_limits<int>::min());
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        row_min[i] = min(row_min[i], matrix[i][j]);
        col_max[j] = max(col_max[j], matrix[i][j]);
      }
    }
    vector<int> result;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == row_min[i] && matrix[i][j] == col_max[j]) {
          result.push_back(matrix[i][j]);
        }
      }
    }
    return result;
  }
};
