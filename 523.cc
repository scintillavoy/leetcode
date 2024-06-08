#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    m[0] = -1;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      sum %= k;
      if (m.count(sum) == 0) {
        m[sum] = i;
      } else if (i - m[sum] >= 2) {
        return true;
      }
    }
    return false;
  }
};
