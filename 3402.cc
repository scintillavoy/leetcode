#include <vector>
using namespace std;

class Solution {
 public:
  int minimumOperations(vector<vector<int>>& grid) {
    int num_of_operations = 0;
    for (int i = 1; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] <= grid[i - 1][j]) {
          num_of_operations += grid[i - 1][j] + 1 - grid[i][j];
          grid[i][j] = grid[i - 1][j] + 1;
        }
      }
    }
    return num_of_operations;
  }
};
