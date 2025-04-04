#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int distinctAverages(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    unordered_set<double> averages;
    int n = nums.size();
    for (int i = 0; i < n / 2; ++i) {
      averages.insert(((double)nums[i] + nums[n - 1 - i]) / 2);
    }
    return averages.size();
  }
};
