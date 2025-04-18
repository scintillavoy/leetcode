#include <vector>
using namespace std;

class Solution {
 public:
  long long zeroFilledSubarray(vector<int>& nums) {
    long long result = 0;
    int length = 0;
    for (int i = 0; i <= nums.size(); ++i) {
      if (i == nums.size() || nums[i] != 0) {
        result += (long long)length * (length + 1) / 2;
        length = 0;
      } else {
        ++length;
      }
    }
    return result;
  }
};
