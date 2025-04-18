#include <algorithm>
using namespace std;

class Solution {
 public:
  int generateKey(int num1, int num2, int num3) {
    int key = 0;
    int multiplier = 1;
    for (int i = 0; i < 4; ++i) {
      key += min({num1 % 10, num2 % 10, num3 % 10}) * multiplier;
      num1 /= 10;
      num2 /= 10;
      num3 /= 10;
      multiplier *= 10;
    }
    return key;
  }
};
