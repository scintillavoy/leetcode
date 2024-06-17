#include <cmath>
using namespace std;

class Solution {
 public:
  bool judgeSquareSum(int c) {
    int left = 0;
    int right = sqrt(c);
    while (left <= right) {
      long long sum = (long long)left * left + right * right;
      if (sum < c) {
        ++left;
      } else if (sum > c) {
        --right;
      } else {
        return true;
      }
    }
    return false;
  }
};
