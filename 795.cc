#include <vector>
using namespace std;

class Solution {
 public:
  int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    return count(nums, right) - count(nums, left - 1);
  }

 private:
  int count(const vector<int>& nums, int max_num) {
    int result = 0;
    int running_count = 0;
    for (const auto num : nums) {
      if (num <= max_num) {
        ++running_count;
      } else {
        running_count = 0;
      }
      result += running_count;
    }
    return result;
  }
};
