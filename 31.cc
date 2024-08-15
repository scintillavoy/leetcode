#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int left = nums.size() - 2;
    while (left >= 0 && nums[left] >= nums[left + 1]) {
      --left;
    }
    if (left >= 0) {
      int upper = nums.size() - 1;
      while (nums[left] >= nums[upper]) {
        --upper;
      }
      swap(nums[left], nums[upper]);
    }
    reverse(nums.begin() + left + 1, nums.end());
  }
};
