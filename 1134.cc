#include <cmath>
using namespace std;

class Solution {
 public:
  bool isArmstrong(int n) {
    int num = n;
    int num_of_digits = 0;
    while (num > 0) {
      ++num_of_digits;
      num /= 10;
    }
    int sum_of_powers = 0;
    num = n;
    while (num > 0) {
      sum_of_powers += pow(num % 10, num_of_digits);
      num /= 10;
    }
    return n == sum_of_powers;
  }
};
