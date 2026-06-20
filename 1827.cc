#include <vector>
using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int num_of_operations = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] >= nums[i]) {
        num_of_operations += nums[i - 1] + 1 - nums[i];
        nums[i] = nums[i - 1] + 1;
      }
    }
    return num_of_operations;
  }
};
