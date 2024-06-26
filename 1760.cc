#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumSize(vector<int>& nums, int maxOperations) {
    int start = 1, end = *max_element(nums.cbegin(), nums.cend());
    while (start <= end) {
      int mid = start + (end - start) / 2;
      int operations = 0;
      for (const auto num : nums) {
        operations += (num - 1) / mid;
      }
      if (operations <= maxOperations) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return start;
  }
};
