#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  int findClosestNumber(vector<int>& nums) {
    int closest_index = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (abs(nums[i]) < abs(nums[closest_index])) {
        closest_index = i;
      } else if (abs(nums[i]) == abs(nums[closest_index]) &&
                 nums[i] > nums[closest_index]) {
        closest_index = i;
      }
    }
    return nums[closest_index];
  }
};
