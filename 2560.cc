#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minCapability(vector<int>& nums, int k) {
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int num_of_steals = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] <= mid) {
          ++num_of_steals;
          if (num_of_steals == k) {
            break;
          }
          ++i;
        }
      }
      if (num_of_steals >= k) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
};
