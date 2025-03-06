#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    int sum = 0;
    unordered_set<int> found_nums;
    vector<int> result(2);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        sum += grid[i][j];
        if (found_nums.contains(grid[i][j])) {
          result[0] = grid[i][j];
        } else {
          found_nums.insert(grid[i][j]);
        }
      }
    }
    result[1] = n * n * (n * n + 1) / 2 - sum + result[0];
    return result;
  }
};
