#include <algorithm>
#include <limits>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    vector<long long> prefix_sum(nums.size() + 1);
    for (int i = 0; i < nums.size(); ++i) {
      prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }
    unordered_map<int, int> num_to_index;
    long long max_sum = numeric_limits<long long>::min();
    for (int i = 0; i < nums.size(); ++i) {
      if (num_to_index.contains(nums[i] - k)) {
        long long sum =
            prefix_sum[i + 1] - prefix_sum[num_to_index[nums[i] - k]];
        max_sum = max(max_sum, sum);
      }
      if (num_to_index.contains(nums[i] + k)) {
        long long sum =
            prefix_sum[i + 1] - prefix_sum[num_to_index[nums[i] + k]];
        max_sum = max(max_sum, sum);
      }
      if (!num_to_index.contains(nums[i]) ||
          prefix_sum[i + 1] - prefix_sum[num_to_index[nums[i]]] < nums[i]) {
        num_to_index[nums[i]] = i;
      }
    }
    return (max_sum == numeric_limits<long long>::min() ? 0 : max_sum);
  }
};
