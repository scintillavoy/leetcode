#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int countElements(vector<int>& nums) {
    int count = 0;
    auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
    for (const auto num : nums) {
      if (*min_it < num && num < *max_it) {
        ++count;
      }
    }
    return count;
  }
};
