#include <vector>
using namespace std;

class Solution {
 public:
  int sumIndicesWithKSetBits(vector<int>& nums, int k) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int index = i;
      int num_of_set_bits = 0;
      while (index > 0) {
        num_of_set_bits += index & 1;
        index >>= 1;
      }
      if (num_of_set_bits == k) {
        sum += nums[i];
      }
    }
    return sum;
  }
};
