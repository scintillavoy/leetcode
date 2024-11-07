#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int largestCombination(vector<int>& candidates) {
    vector<int> counts_by_bit(32);
    int max_count = 0;
    for (const auto candidate : candidates) {
      for (int i = 0; i < 32; ++i) {
        if ((candidate & (1 << i)) != 0) {
          ++counts_by_bit[i];
          max_count = max(max_count, counts_by_bit[i]);
        }
      }
    }
    return max_count;
  }
};
