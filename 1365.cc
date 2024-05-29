#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> counts(101);
    for (const auto num : nums) {
      ++counts[num];
    }
    for (int i = 1; i < counts.size(); ++i) {
      counts[i] += counts[i - 1];
    }
    vector<int> result(nums.size());
    for (int i = 0; i < result.size(); ++i) {
      if (nums[i] - 1 < 0) {
        continue;
      }
      result[i] = counts[nums[i] - 1];
    }
    return result;
  }
};
