#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int deleteAndEarn(vector<int>& nums) {
    vector<int> counts(10001);
    for (const auto num : nums) {
      ++counts[num];
    }
    int prev2 = 0;
    int prev = counts[1];
    for (int i = 2; i < counts.size(); ++i) {
      int curr = max(prev2 + i * counts[i], prev);
      prev2 = prev;
      prev = curr;
    }
    return prev;
  }
};
