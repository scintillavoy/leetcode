#include <vector>
using namespace std;

class Solution {
 public:
  int maxOperations(vector<int>& nums) {
    int num_of_operations = 1;
    int score = nums[0] + nums[1];
    for (int i = 2; i + 1 < nums.size(); i += 2) {
      if (nums[i] + nums[i + 1] != score) {
        break;
      }
      ++num_of_operations;
    }
    return num_of_operations;
  }
};
