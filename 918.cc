#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int curr_max = 0;
    int max_sum = nums[0];
    int curr_min = 0;
    int min_sum = nums[0];
    int total_sum = 0;
    for (const auto num : nums) {
      curr_max = max(curr_max, 0) + num;
      max_sum = max(max_sum, curr_max);

      curr_min = min(curr_min, 0) + num;
      min_sum = min(min_sum, curr_min);

      total_sum += num;
    }

    if (total_sum == min_sum) {
      return max_sum;
    }

    return max(max_sum, total_sum - min_sum);
  }
};
