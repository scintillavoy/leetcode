#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumDifference(vector<int>& nums) {
    int max_diff = -1;
    int min_num = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (min_num >= nums[i]) {
        min_num = nums[i];
      } else {
        max_diff = max(max_diff, nums[i] - min_num);
      }
    }
    return max_diff;
  }
};
