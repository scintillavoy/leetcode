#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestOnes(vector<int>& nums, int k) {
    int result = 0;
    int left = 0;
    for (int right = 0; right < nums.size(); ++right) {
      if (nums[right] == 0) {
        --k;
      }
      while (k < 0) {
        if (nums[left] == 0) {
          ++k;
        }
        ++left;
      }
      result = max(result, right - left + 1);
    }
    return result;
  }
};
