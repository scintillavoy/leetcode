#include <vector>
using namespace std;

class Solution {
 public:
  int countServers(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> counts_by_row(m);
    vector<int> counts_by_col(n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          ++counts_by_row[i];
          ++counts_by_col[j];
        }
      }
    }
    int result = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1 && (counts_by_row[i] > 1 || counts_by_col[j] > 1)) {
          ++result;
        }
      }
    }
    return result;
  }
};
