#include <deque>
#include <vector>
using namespace std;

class Solution {
 public:
  int minKBitFlips(vector<int>& nums, int k) {
    deque<int> flips;
    int target = 0;
    int result = 0;
    for (int i = 0; i < nums.size() - k + 1; ++i) {
      if (!flips.empty() && flips.front() == i) {
        target ^= 1;
        flips.pop_front();
      }
      if (nums[i] == target) {
        target ^= 1;
        flips.push_back(i + k);
        ++result;
      }
    }
    for (int i = nums.size() - k + 1; i < nums.size(); ++i) {
      if (!flips.empty() && flips.front() == i) {
        target ^= 1;
        flips.pop_front();
      }
      if (nums[i] == target) {
        return -1;
      }
    }
    return result;
  }
};
