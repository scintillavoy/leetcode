#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int m = rowSum.size();
    int n = colSum.size();
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (rowSum[i] <= colSum[j]) {
          matrix[i][j] = rowSum[i];
          rowSum[i] = 0;
          colSum[j] -= matrix[i][j];
          break;
        }
        matrix[i][j] = colSum[j];
        rowSum[i] -= matrix[i][j];
        colSum[j] = 0;
      }
    }
    return matrix;
  }
};
