#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int reductionOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int total = 0;
    int curr = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] < nums[i]) {
        ++curr;
      }
      total += curr;
    }
    return total;
  }
};
