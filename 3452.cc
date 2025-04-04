#include <vector>
using namespace std;

class Solution {
 public:
  int sumOfGoodNumbers(vector<int>& nums, int k) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i - k >= 0 && nums[i - k] >= nums[i]) {
        continue;
      }
      if (i + k < nums.size() && nums[i + k] >= nums[i]) {
        continue;
      }
      sum += nums[i];
    }
    return sum;
  }
};
