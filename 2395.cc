#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool findSubarrays(vector<int>& nums) {
    unordered_set<int> sums;
    for (int i = 1; i < nums.size(); ++i) {
      int sum = nums[i - 1] + nums[i];
      if (sums.contains(sum)) {
        return true;
      }
      sums.insert(sum);
    }
    return false;
  }
};
