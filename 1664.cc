#include <vector>
using namespace std;

class Solution {
 public:
  int waysToMakeFair(vector<int>& nums) {
    vector<int> sums(2);
    for (int i = 0; i < nums.size(); ++i) {
      sums[i % 2] += nums[i];
    }
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sums[i % 2] -= nums[i];
      if (sums[0] == sums[1]) {
        ++count;
      }
      sums[(i + 1) % 2] += nums[i];
    }
    return count;
  }
};
