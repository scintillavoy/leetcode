#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> remainders;
    for (int i = 0; i < nums.size(); ++i) {
      if (i != 0) {
        nums[i] += nums[i - 1];
      }
      while (nums[i] < 0) {
        nums[i] += k;
      }
      nums[i] %= k;
      ++remainders[nums[i]];
    }
    ++remainders[0];
    int result = 0;
    for (const auto [k, v] : remainders) {
      result += v * (v - 1) / 2;
    }
    return result;
  }
};
