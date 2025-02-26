#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxAbsoluteSum(vector<int>& nums) {
    int max_absolute_sum = 0;
    int running_positive_sum = 0;
    int running_negative_sum = 0;
    for (const auto num : nums) {
      running_positive_sum = max(running_positive_sum + num, 0);
      running_negative_sum = min(running_negative_sum + num, 0);
      max_absolute_sum = max(
          {max_absolute_sum, running_positive_sum, abs(running_negative_sum)});
    }
    return max_absolute_sum;
  }
};
