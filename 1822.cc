#include <vector>
using namespace std;

class Solution {
 public:
  int arraySign(vector<int>& nums) {
    int result = 1;
    for (const auto num : nums) {
      if (num == 0) {
        return 0;
      }
      if (num < 0) {
        result *= -1;
      }
    }
    return result;
  }
};
