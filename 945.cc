#include <vector>
using namespace std;

class Solution {
 public:
  int minIncrementForUnique(vector<int>& nums) {
    vector<int> counts(200'001);
    for (const auto num : nums) {
      ++counts[num];
    }
    int result = 0;
    int carry = 0;
    for (int i = 0; i < counts.size(); ++i) {
      if (carry + counts[i] <= 1) {
        carry = 0;
        continue;
      }
      carry += counts[i] - 1;
      result += carry;
    }
    return result;
  }
};
