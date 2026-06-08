#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    int max_length = 1;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == -1) {
        continue;
      }
      int length = 0;
      int curr_index = i;
      while (nums[curr_index] != -1) {
        int next_index = nums[curr_index];
        nums[curr_index] = -1;
        ++length;
        curr_index = next_index;
      }
      max_length = max(max_length, length);
    }
    return max_length;
  }
};
