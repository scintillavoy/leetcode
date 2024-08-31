#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    return lower_bound(nums.cbegin(), nums.cend(), target) - nums.cbegin();
  }
};
