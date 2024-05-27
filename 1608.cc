#include <vector>
using namespace std;

class Solution {
 public:
  int specialArray(vector<int>& nums) {
    vector<int> counts(1001);
    for (const auto num : nums) {
      ++counts[num];
    }
    for (int i = 999; i >= 0; --i) {
      counts[i] += counts[i + 1];
      if (counts[i] == i) {
        return i;
      }
    }
    return -1;
  }
};
