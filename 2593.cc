#include <vector>
using namespace std;

class Solution {
 public:
  long long findScore(vector<int>& nums) {
    long long score = 0;
    int left = 0;
    while (left < nums.size()) {
      int right = left;
      while (right + 1 < nums.size() && nums[right] > nums[right + 1]) {
        ++right;
      }
      int next_left = right + 2;
      while (left <= right) {
        score += nums[right];
        right -= 2;
      }
      left = next_left;
    }
    return score;
  }
};
