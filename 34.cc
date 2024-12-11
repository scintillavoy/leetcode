#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int start_index =
        lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (start_index == nums.size() || nums[start_index] != target) {
      return {-1, -1};
    }
    int end_index =
        upper_bound(nums.begin(), nums.end(), target) - 1 - nums.begin();
    return {start_index, end_index};
  }
};
