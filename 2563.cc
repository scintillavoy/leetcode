#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    long long num_of_pairs = 0;
    sort(nums.begin(), nums.end());
    for (const auto num : nums) {
      auto lower_it = lower_bound(nums.begin(), nums.end(), lower - num);
      auto upper_it = upper_bound(nums.begin(), nums.end(), upper - num);
      num_of_pairs += upper_it - lower_it;
      if (lower - num <= num && num <= upper - num) {
        --num_of_pairs;
      }
    }
    num_of_pairs /= 2;
    return num_of_pairs;
  }
};
