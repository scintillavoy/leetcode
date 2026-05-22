#include <vector>
using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[0] > nums[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    int rotation = low;
    low = 0;
    high = n - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int rotated_mid = (mid + rotation) % n;
      if (target == nums[rotated_mid]) {
        return rotated_mid;
      } else if (target < nums[rotated_mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return -1;
  }
};
