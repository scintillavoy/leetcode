#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int i = 0;
    while (i < nums.size()) {
      int j = i + 1;
      int k = nums.size() - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          result.push_back({nums[i], nums[j], nums[k]});
          do {
            ++j;
          } while (j < k && nums[j - 1] == nums[j]);
        } else if (sum < 0) {
          ++j;
        } else {
          --k;
        }
      }
      do {
        ++i;
      } while (i < nums.size() && nums[i - 1] == nums[i]);
    }
    return result;
  }
};
