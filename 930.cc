#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> prefix_sum;
    prefix_sum[0] = 1;
    int count = 0;
    int sum = 0;
    for (const auto num : nums) {
      sum += num;
      if (prefix_sum.contains(sum - goal)) {
        count += prefix_sum[sum - goal];
      }
      ++prefix_sum[sum];
    }
    return count;
  }
};
