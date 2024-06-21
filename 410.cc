#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int splitArray(vector<int>& nums, int k) {
    int start = 0, end = 0;
    for (const auto num : nums) {
      start = max(start, num);
      end += num;
    }
    while (start <= end) {
      int mid = start + (end - start) / 2;
      int sum = 0;
      int count = 1;
      for (int i = 0; i < nums.size(); ++i) {
        if (sum + nums[i] > mid) {
          sum = nums[i];
          ++count;
        } else {
          sum += nums[i];
        }
      }
      if (count <= k) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return start;
  }
};
