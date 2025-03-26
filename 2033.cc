#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  int minOperations(vector<vector<int>>& grid, int x) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> nums(m * n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        nums[i * n + j] = grid[i][j];
      }
    }
    nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    int median = nums[nums.size() / 2];
    int min_num_of_operations = 0;
    for (const auto& num : nums) {
      int diff = abs(num - median);
      if (diff % x != 0) {
        return -1;
      }
      min_num_of_operations += diff / x;
    }
    return min_num_of_operations;
  }
};
