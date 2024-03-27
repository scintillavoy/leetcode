#include <vector>
using namespace std;

class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int answer = 0;
    int product = 1;
    int left = 0, right = 0;
    while (left < nums.size()) {
      while (right < nums.size() && product * nums[right] < k) {
        product *= nums[right];
        ++right;
      }
      answer += right - left;
      if (right - left != 0) {
        product /= nums[left];
      }
      ++left;
      if (left > right) {
        ++right;
      }
    }
    return answer;
  }
};
