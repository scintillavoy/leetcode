#include <vector>
using namespace std;

class Solution {
 public:
  int minimumSwaps(vector<int>& nums) {
    int min_val = nums[0], min_idx = 0;
    int max_val = nums[0], max_idx = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < min_val) {
        min_val = nums[i];
        min_idx = i;
      }
      if (nums[i] >= max_val) {
        max_val = nums[i];
        max_idx = i;
      }
    }
    int num_of_swaps = nums.size() - 1 - max_idx + min_idx;
    if (max_idx < min_idx) {
      --num_of_swaps;
    }
    return num_of_swaps;
  }
};
