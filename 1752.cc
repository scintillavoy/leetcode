#include <vector>
using namespace std;

class Solution {
 public:
  bool check(vector<int>& nums) {
    bool rotated = false;
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] > nums[i + 1]) {
        if (rotated) {
          return false;
        } else {
          rotated = true;
        }
      }
    }
    if (nums.back() > nums.front()) {
      if (rotated) {
        return false;
      }
    }
    return true;
  }
};
