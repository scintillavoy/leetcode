#include <vector>
using namespace std;

class Solution {
 public:
  int differenceOfSum(vector<int>& nums) {
    int diff = 0;
    for (auto num : nums) {
      diff += num;
      while (num > 0) {
        diff -= num % 10;
        num /= 10;
      }
    }
    return diff;
  }
};
