#include <vector>
using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int min_operations = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] != nums[i]) {
        ++min_operations;
      }
    }
    return min_operations;
  }
};
