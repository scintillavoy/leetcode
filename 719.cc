#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int start = 0, end = nums.back() - nums.front();
    while (start <= end) {
      int mid = start + (end - start) / 2;
      int count = 0;
      int left = 0;
      for (int right = 1; right < nums.size(); ++right) {
        while (nums[right] - nums[left] > mid) {
          ++left;
        }
        count += right - left;
      }
      if (count >= k) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return start;
  }
};
