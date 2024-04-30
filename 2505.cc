#include <vector>
using namespace std;

class Solution {
 public:
  long long subsequenceSumOr(vector<int>& nums) {
    vector<int> counts(64 + 1);
    for (int i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      for (int j = 0; num > 0; ++j, num >>= 1) {
        if (num & 1 == 1) {
          ++counts[j];
        }
      }
    }
    long long answer = 0;
    for (int i = 0; i < 64; ++i) {
      if (counts[i] == 0) {
        continue;
      }
      answer |= ((long long)1 << i);
      counts[i + 1] += counts[i] / 2;
    }
    return answer;
  }
};
