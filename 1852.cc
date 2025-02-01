#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> distinctNumbers(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    for (int i = 0; i < k - 1; ++i) {
      ++counts[nums[i]];
    }
    vector<int> result;
    for (int i = k - 1; i < nums.size(); ++i) {
      ++counts[nums[i]];
      result.push_back(counts.size());
      --counts[nums[i - k + 1]];
      if (counts[nums[i - k + 1]] == 0) {
        counts.erase(nums[i - k + 1]);
      }
    }
    return result;
  }
};
