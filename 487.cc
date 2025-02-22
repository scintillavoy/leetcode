#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int max_length = 0;
    int last_length_ended_with_zero = 0;
    int current_length = 0;
    for (const auto num : nums) {
      ++current_length;
      if (num == 0) {
        current_length -= last_length_ended_with_zero;
        last_length_ended_with_zero = current_length;
      }
      max_length = max(max_length, current_length);
    }
    return max_length;
  }
};
