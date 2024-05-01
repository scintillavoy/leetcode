#include <vector>
using namespace std;

class Solution {
 public:
  bool removeOnes(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 1; i < m; ++i) {
      int value = grid[0][0] ^ grid[i][0];
      for (int j = 1; j < n; ++j) {
        if (grid[0][j] ^ grid[i][j] != value) {
          return false;
        }
      }
    }
    return true;
  }
};
