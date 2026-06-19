#include <vector>
using namespace std;

class Solution {
 public:
  int missingMultiple(vector<int>& nums, int k) {
    vector<bool> seen(nums.size());
    for (const auto num : nums) {
      if (num % k == 0 && num / k - 1 < seen.size()) {
        seen[num / k - 1] = true;
      }
    }
    for (int i = 0; i < seen.size(); ++i) {
      if (!seen[i]) {
        return k * (i + 1);
      }
    }
    return k * (seen.size() + 1);
  }
};
