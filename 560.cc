#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> counts{{0, 1}};
    int prefix_sum = 0;
    int result = 0;
    for (const auto num : nums) {
      prefix_sum += num;
      result += counts[prefix_sum - k];
      ++counts[prefix_sum];
    }
    return result;
  }
};
