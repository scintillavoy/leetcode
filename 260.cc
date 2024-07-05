#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int mask = 0;
    for (const auto num : nums) {
      mask ^= num;
    }
    int x = 0;
    for (const auto num : nums) {
      if (num > (num ^ mask)) {
        x ^= num;
      }
    }
    return {x, x ^ mask};
  }
};
