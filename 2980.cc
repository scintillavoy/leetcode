#include <vector>
using namespace std;

class Solution {
 public:
  bool hasTrailingZeros(vector<int>& nums) {
    int count = 0;
    for (const auto num : nums) {
      if ((num & 1) == 0) {
        ++count;
        if (count >= 2) {
          return true;
        }
      }
    }
    return false;
  }
};
