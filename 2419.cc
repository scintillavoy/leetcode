#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int max_num = 0;
    int max_length = 0;
    int curr_length = 0;
    for (const auto num : nums) {
      if (num == max_num) {
        ++curr_length;
        max_length = max(max_length, curr_length);
      } else if (num > max_num) {
        max_num = num;
        curr_length = 1;
        max_length = 1;
      } else {
        curr_length = 0;
      }
    }
    return max_length;
  }
};
