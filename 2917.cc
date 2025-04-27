#include <vector>
using namespace std;

class Solution {
 public:
  int findKOr(vector<int>& nums, int k) {
    vector<int> counts;
    for (auto num : nums) {
      int index = 0;
      while (num > 0) {
        if (index >= counts.size()) {
          counts.push_back(0);
        }
        counts[index] += num & 1;
        num >>= 1;
        ++index;
      }
    }
    int result = 0;
    for (auto it = counts.rbegin(); it != counts.rend(); ++it) {
      result <<= 1;
      if (*it >= k) {
        ++result;
      }
    }
    return result;
  }
};
