#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<long long, int> m;
    for (int i = 0; i < nums.size(); ++i) {
      if (m.count(nums[i]) == 1) {
        return {m[nums[i]], i};
      }
      m[target - nums[i]] = i;
    }
    return {};
  }
};
