#include <vector>
using namespace std;

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int result = 0;
    int start = 0;
    for (int end = 2; end <= nums.size(); ++end) {
      if (end - start < 2) {
        continue;
      }
      if (end == nums.size() ||
          nums[end - 2] - nums[end - 1] != nums[end - 1] - nums[end]) {
        int n = end - start - 2;
        result += n * (n + 1) / 2;
        start = end - 1;
      }
    }
    return result;
  }
};
