#include <vector>
using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int min_num_of_operations = 0;
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (nums[i] == 0) {
        ++min_num_of_operations;
        nums[i] ^= 1;
        nums[i + 1] ^= 1;
        nums[i + 2] ^= 1;
      }
    }
    if (nums[nums.size() - 2] == 0 || nums[nums.size() - 1] == 0) {
      return -1;
    }
    return min_num_of_operations;
  }
};
