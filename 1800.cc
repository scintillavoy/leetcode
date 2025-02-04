#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxAscendingSum(vector<int>& nums) {
    int max_sum = nums[0];
    int curr_sum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] >= nums[i]) {
        curr_sum = 0;
      }
      curr_sum += nums[i];
      max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
  }
};
