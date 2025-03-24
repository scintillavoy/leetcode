#include <numeric>
using namespace std;

class Solution {
 public:
  int commonFactors(int a, int b) {
    int num_of_common_factors = 0;
    int gcd_value = gcd(a, b);
    for (int i = 1; i * i <= gcd_value; ++i) {
      if (gcd_value % i == 0) {
        ++num_of_common_factors;
        if (i * i != gcd_value) {
          ++num_of_common_factors;
        }
      }
    }
    return num_of_common_factors;
  }
};
