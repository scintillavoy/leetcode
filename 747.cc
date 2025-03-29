#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int dominantIndex(vector<int>& nums) {
    int max_num_index = 0;
    int second_max_num_index = 1;
    if (nums[1] > nums[0]) {
      swap(max_num_index, second_max_num_index);
    }
    for (int i = 2; i < nums.size(); ++i) {
      if (nums[i] > nums[max_num_index]) {
        second_max_num_index = max_num_index;
        max_num_index = i;
      } else if (nums[i] > nums[second_max_num_index]) {
        second_max_num_index = i;
      }
    }
    if (nums[max_num_index] >= 2 * nums[second_max_num_index]) {
      return max_num_index;
    }
    return -1;
  }
};
