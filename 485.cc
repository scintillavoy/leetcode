#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int max_count = 0;
    int count = 0;
    for (const auto num : nums) {
      if (num == 1) {
        ++count;
        max_count = max(max_count, count);
      } else {
        count = 0;
      }
    }
    return max_count;
  }
};
