#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isMajorityElement(vector<int>& nums, int target) {
    int first_index =
        lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    return first_index + nums.size() / 2 < nums.size() &&
           nums[first_index + nums.size() / 2] == target;
  }
};
