#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums) {
    vector<int> prefix_sum(nums.size() + 1);
    for (int i = 0; i < nums.size(); ++i) {
      prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }
    int total_sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      total_sum += prefix_sum[i + 1] - prefix_sum[max(0, i - nums[i])];
    }
    return total_sum;
  }
};
