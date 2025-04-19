#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> leftRightDifference(vector<int>& nums) {
    int sum = 0;
    for (const auto num : nums) {
      sum += num;
    }
    vector<int> result(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      sum -= nums[i];
      result[i] = abs(sum);
      sum -= nums[i];
    }
    return result;
  }
};
