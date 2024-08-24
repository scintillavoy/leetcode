#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int max_frequency = 1;
    int left = 0;
    long long num_of_operations = 0;
    for (int right = 1; right < nums.size(); ++right) {
      num_of_operations +=
          (long long)(right - left) * (nums[right] - nums[right - 1]);
      while (num_of_operations > k) {
        num_of_operations -= nums[right] - nums[left];
        ++left;
      }
      max_frequency = max(max_frequency, right - left + 1);
    }
    return max_frequency;
  }
};
