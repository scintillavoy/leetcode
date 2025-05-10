#include <vector>
using namespace std;

class Solution {
 public:
  long long minSum(vector<int>& nums1, vector<int>& nums2) {
    bool has_zero1 = false;
    long long sum1 = 0;
    for (const auto num : nums1) {
      if (num == 0) {
        has_zero1 = true;
        sum1 += 1;
      } else {
        sum1 += num;
      }
    }
    bool has_zero2 = false;
    long long sum2 = 0;
    for (const auto num : nums2) {
      if (num == 0) {
        has_zero2 = true;
        sum2 += 1;
      } else {
        sum2 += num;
      }
    }
    if (sum1 < sum2) {
      if (!has_zero1) {
        return -1;
      }
      return sum2;
    }
    if (sum2 < sum1) {
      if (!has_zero2) {
        return -1;
      }
      return sum1;
    }
    return sum1;
  }
};
