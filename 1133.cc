#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int largestUniqueNumber(vector<int>& nums) {
    vector<int> counts(*max_element(nums.cbegin(), nums.cend()) + 1);
    for (const auto num : nums) {
      ++counts[num];
    }
    for (int i = counts.size() - 1; i >= 0; --i) {
      if (counts[i] == 1) {
        return i;
      }
    }
    return -1;
  }
};
