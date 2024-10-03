#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int minSubarray(vector<int>& nums, int p) {
    int total_remainder = 0;
    for (const auto num : nums) {
      total_remainder = (total_remainder + num) % p;
    }
    if (total_remainder == 0) {
      return 0;
    }
    unordered_map<int, int> remainder_to_index;
    remainder_to_index[0] = -1;
    int curr_remainder = 0;
    int min_length = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
      curr_remainder = (curr_remainder + nums[i]) % p;
      int target = (curr_remainder - total_remainder + p) % p;
      if (remainder_to_index.contains(target)) {
        min_length = min(min_length, i - remainder_to_index[target]);
      }
      remainder_to_index[curr_remainder] = i;
    }
    return min_length == nums.size() ? -1 : min_length;
  }
};
