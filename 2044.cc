#include <vector>
using namespace std;

class Solution {
 public:
  int countMaxOrSubsets(vector<int>& nums) {
    int max_num = 0;
    for (const auto num : nums) {
      max_num |= num;
    }
    vector<int> counts(max_num << 1);
    counts[0] = 1;
    for (const auto num : nums) {
      for (int i = max_num; i >= 0; --i) {
        counts[i | num] += counts[i];
      }
    }
    return counts[max_num];
  }
};
