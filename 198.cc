#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    int prev = nums[0], curr = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); ++i) {
      int temp = curr;
      curr = max(prev + nums[i], curr);
      prev = temp;
    }
    return curr;
  }
};
