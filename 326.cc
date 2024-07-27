#include <cmath>
using namespace std;

#define E 1e-9

class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n <= 0) {
      return false;
    }
    double log3 = log(n) / log(3);
    return abs(round(log3) - log3) < E;
  }
};
