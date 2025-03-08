#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    int right = nums.size() - 1;
    for (int left = 0; left < right; ++left) {
      while (left < right && nums[left] % 2 == 1) {
        swap(nums[left], nums[right]);
        --right;
      }
    }
    return nums;
  }
};
