#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    int sum = 0;
    for (int i = 0; i < k; ++i) {
      sum += nums[i];
    }
    double max_average = (double)sum / k;
    for (int i = k; i < nums.size(); ++i) {
      sum = sum - nums[i - k] + nums[i];
      max_average = max(max_average, (double)sum / k);
    }
    return max_average;
  }
};
