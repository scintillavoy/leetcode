#include <vector>
using namespace std;

class Solution {
 public:
  int waysToSplitArray(vector<int>& nums) {
    long long right_sum = 0;
    for (const auto num : nums) {
      right_sum += num;
    }
    long long left_sum = 0;
    int num_of_splits = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      left_sum += nums[i];
      right_sum -= nums[i];
      if (left_sum >= right_sum) {
        ++num_of_splits;
      }
    }
    return num_of_splits;
  }
};
