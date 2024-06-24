#include <vector>
using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    int result = 0;
    for (const auto num : nums) {
      if (num < k) {
        ++result;
      }
    }
    return result;
  }
};
