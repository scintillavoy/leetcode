#include <vector>
using namespace std;

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (mid % 2 == 0) {
        if (mid == nums.size() - 1 || nums[mid] != nums[mid + 1]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      } else {
        if (mid == 0 || nums[mid - 1] != nums[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
    }
    return nums[low];
  }
};
