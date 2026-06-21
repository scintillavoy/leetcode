#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  long long maximumMedianSum(vector<int>& nums) {
    long long sum = 0;
    sort(nums.rbegin(), nums.rend());
    for (int i = 0; i < nums.size() / 3; ++i) {
      sum += nums[1 + 2 * i];
    }
    return sum;
  }
};
