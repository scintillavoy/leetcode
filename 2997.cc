#include <vector>
using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    int num = k;
    for (int i = 0; i < nums.size(); ++i) {
      num = num ^ nums[i];
    }
    int count = 0;
    while (num > 0) {
      count += num & 1;
      num >>= 1;
    }
    return count;
  }
};
