#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size();
    vector<int> lis_length(n);
    vector<int> seq;
    for (int i = 0; i < n; ++i) {
      auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
      if (it == seq.end()) {
        seq.push_back(nums[i]);
      } else {
        *it = nums[i];
      }
      lis_length[i] = seq.size();
    }
    seq.clear();
    int min_removals = n - 3;
    for (int i = n - 1; i >= 0; --i) {
      auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
      if (it == seq.end()) {
        seq.push_back(nums[i]);
      } else {
        *it = nums[i];
      }
      if (seq.size() >= 2 && lis_length[i] >= 2) {
        min_removals =
            min(min_removals, n - (int)seq.size() - lis_length[i] + 1);
      }
    }
    return min_removals;
  }
};
