#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumSubarrayLength(vector<int>& nums, int k) {
    if (k == 0) {
      return 1;
    }
    vector<int> bit_frequencies(32);
    int min_length = numeric_limits<int>::max();
    int left = 0;
    int curr_or = 0;
    for (int right = 0; right < nums.size(); ++right) {
      for (int i = 0; i < bit_frequencies.size(); ++i) {
        if ((nums[right] & (1 << i)) != 0) {
          ++bit_frequencies[i];
        }
      }
      curr_or |= nums[right];
      while (curr_or >= k) {
        min_length = min(min_length, right - left + 1);
        for (int i = 0; i < bit_frequencies.size(); ++i) {
          if ((nums[left] & (1 << i)) != 0) {
            --bit_frequencies[i];
            if (bit_frequencies[i] == 0) {
              curr_or &= ~(1 << i);
            }
          }
        }
        ++left;
      }
    }
    return min_length == numeric_limits<int>::max() ? -1 : min_length;
  }
};
