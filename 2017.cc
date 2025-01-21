#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  long long gridGame(vector<vector<int>>& grid) {
    int n = grid[0].size();
    long long sum_top = 0;
    long long sum_bottom = 0;
    for (int i = 1; i < n; ++i) {
      sum_top += grid[0][i];
    }
    long long min_sum = sum_top;
    for (int i = 1; i < n; ++i) {
      sum_top -= grid[0][i];
      sum_bottom += grid[1][i - 1];
      min_sum = min(min_sum, max(sum_top, sum_bottom));
    }
    return min_sum;
  }
};
