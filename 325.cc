#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<long long, int> prefix_sum_to_index;
    prefix_sum_to_index[0] = -1;
    long long prefix_sum = 0;
    int max_length = 0;
    for (int i = 0; i < nums.size(); ++i) {
      prefix_sum += nums[i];
      if (prefix_sum_to_index.contains(prefix_sum - k)) {
        max_length = max(max_length, i - prefix_sum_to_index[prefix_sum - k]);
      }
      if (!prefix_sum_to_index.contains(prefix_sum)) {
        prefix_sum_to_index[prefix_sum] = i;
      }
    }
    return max_length;
  }
};
