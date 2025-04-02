#include <vector>
using namespace std;

class Solution {
 public:
  bool kLengthApart(vector<int>& nums, int k) {
    int gap = k;
    for (const auto num : nums) {
      if (num == 0) {
        ++gap;
        continue;
      }
      if (gap < k) {
        return false;
      }
      gap = 0;
    }
    return true;
  }
};
