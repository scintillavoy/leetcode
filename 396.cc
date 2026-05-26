#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxRotateFunction(vector<int>& nums) {
    int sum = nums[0];
    int current_value = 0;
    for (int i = 1; i < nums.size(); ++i) {
      sum += nums[i];
      current_value += i * nums[i];
    }
    int max_value = current_value;
    for (int i = nums.size() - 1; i > 0; --i) {
      current_value =
          current_value - (nums.size() - 1) * nums[i] + sum - nums[i];
      max_value = max(max_value, current_value);
    }
    return max_value;
  }
};
