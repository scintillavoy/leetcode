#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    long long max_sum = 0;
    long long sum = 0;
    unordered_map<int, int> frequencies;
    int left = 0;
    for (int right = 0; right < nums.size(); ++right) {
      sum += nums[right];
      ++frequencies[nums[right]];
      if (right - left + 1 > k) {
        sum -= nums[left];
        --frequencies[nums[left]];
        if (frequencies[nums[left]] == 0) {
          frequencies.erase(nums[left]);
        }
        ++left;
      }
      if (frequencies.size() == k) {
        max_sum = max(max_sum, sum);
      }
    }
    return max_sum;
  }
};
