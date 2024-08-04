#include <algorithm>
#include <vector>
using namespace std;

#define MOD 1'000'000'007

class Solution {
 public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    vector<int> sums;
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = i; j < n; ++j) {
        sum += nums[j];
        sums.push_back(sum);
      }
    }
    sort(sums.begin(), sums.end());
    int range_sum = 0;
    for (int i = left - 1; i < right; ++i) {
      range_sum = (range_sum + sums[i]) % MOD;
    }
    return range_sum;
  }
};
