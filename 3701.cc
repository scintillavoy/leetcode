#include <vector>
using namespace std;

class Solution {
 public:
  int alternatingSum(vector<int>& nums) {
    int alternating_sum = 0;
    int multiplier = 1;
    for (const auto num : nums) {
      alternating_sum += num * multiplier;
      multiplier *= -1;
    }
    return alternating_sum;
  }
};
