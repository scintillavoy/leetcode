#include <vector>
using namespace std;

class Solution {
 public:
  int findChampion(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); ++i) {
      int sum = 0;
      for (int j = 0; j < grid[i].size(); ++j) {
        sum += grid[i][j];
      }
      if (sum == grid.size() - 1) {
        return i;
      }
    }
    return -1;
  }
};
