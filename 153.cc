#include <vector>
using namespace std;

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[0] > nums[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return low == nums.size() ? nums[0] : nums[low];
  }
};
