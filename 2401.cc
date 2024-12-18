#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestNiceSubarray(vector<int>& nums) {
    int max_length = 0;
    int mask = 0;
    int left = 0;
    for (int right = 0; right < nums.size(); ++right) {
      while ((mask & nums[right]) != 0) {
        mask = mask & (~nums[left]);
        ++left;
      }
      mask |= nums[right];
      max_length = max(max_length, right - left + 1);
    }
    return max_length;
  }
};
