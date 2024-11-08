#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int prefix_xor = 0;
    for (const auto num : nums) {
      prefix_xor ^= num;
    }
    int mask = (1 << maximumBit) - 1;
    vector<int> result(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      result[i] = prefix_xor ^ mask;
      prefix_xor ^= nums[nums.size() - 1 - i];
    }
    return result;
  }
};
