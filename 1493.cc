#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int max_size = 0;
    int start = 0, end = 0;
    while (end < nums.size() && nums[end] == 1) {
      ++end;
    }
    if (end == nums.size()) {
      return nums.size() - 1;
    }
    max_size = max(max_size, end - start);
    while (start < nums.size() && end < nums.size()) {
      ++end;
      while (end < nums.size() && nums[end] == 1) {
        ++end;
      }
      max_size = max(max_size, end - start - 1);
      while (start < nums.size() && nums[start] == 1) {
        ++start;
      }
      ++start;
    }
    return max_size;
  }
};
