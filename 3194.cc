#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  double minimumAverage(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    double min_average = numeric_limits<double>::max();
    for (int i = 0; i < n / 2; ++i) {
      min_average = min(min_average, ((double)nums[i] + nums[n - 1 - i]) / 2);
    }
    return min_average;
  }
};
