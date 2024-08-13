#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumLength(vector<int>& nums) {
    int evens = 0;
    int odds = 0;
    for (const auto num : nums) {
      if (num % 2 == 0) {
        ++evens;
      } else {
        ++odds;
      }
    }
    int alternate_even = 0;
    int next_remainder = 0;
    for (const auto num : nums) {
      if (num % 2 == next_remainder) {
        ++alternate_even;
        next_remainder ^= 1;
      }
    }
    int alternate_odd = 0;
    next_remainder = 1;
    for (const auto num : nums) {
      if (num % 2 == next_remainder) {
        ++alternate_odd;
        next_remainder ^= 1;
      }
    }
    return max({evens, odds, alternate_even, alternate_odd});
  }
};
