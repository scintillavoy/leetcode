#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  long long maximumTripletValue(vector<int>& nums) {
    long long max_triplet_value = 0;
    int max_num = max(nums[0], nums[1]);
    int max_diff = nums[0] - nums[1];
    for (int i = 2; i < nums.size(); ++i) {
      max_triplet_value = max(max_triplet_value, (long long)max_diff * nums[i]);
      max_num = max(max_num, nums[i]);
      max_diff = max(max_diff, max_num - nums[i]);
    }
    return max_triplet_value;
  }
};
