#include <vector>
using namespace std;

class Solution {
 public:
  int minPatches(vector<int>& nums, int n) {
    long long max_num = 0;
    int result = 0;
    int curr = 0;
    while (curr < nums.size()) {
      if (max_num >= n) {
        break;
      }
      if (nums[curr] <= max_num + 1) {
        max_num += nums[curr];
        ++curr;
      } else {
        max_num = 2 * max_num + 1;
        ++result;
      }
    }
    while (max_num < n) {
      max_num = 2 * max_num + 1;
      ++result;
    }
    return result;
  }
};
