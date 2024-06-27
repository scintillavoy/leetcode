#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  int smallestDivisor(vector<int>& nums, int threshold) {
    int start = 1, end = *max_element(nums.cbegin(), nums.cend());
    while (start <= end) {
      int mid = start + (end - start) / 2;
      int result = 0;
      for (const auto num : nums) {
        result += ceil((double)num / mid);
      }
      if (result <= threshold) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return start;
  }
};
