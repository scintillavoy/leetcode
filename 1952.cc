#include <cmath>
using namespace std;

class Solution {
 public:
  bool isThree(int n) {
    int sqrt_n = sqrt(n);
    return is_prime(sqrt_n) && n == sqrt_n * sqrt_n;
  }

 private:
  bool is_prime(int n) {
    if (n < 2) {
      return false;
    }
    for (int i = 2; i <= sqrt(n); ++i) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
};
