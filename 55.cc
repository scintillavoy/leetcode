#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    for (int i = 0, max_index = 0; i < nums.size() && i <= max_index; ++i) {
      if (i == nums.size() - 1) {
        return true;
      }
      max_index = max(max_index, i + nums[i]);
    }
    return false;
  }
};
