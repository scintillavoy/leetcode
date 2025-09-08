#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i < n; ++i) {
      if (is_no_zero_integer(i) && is_no_zero_integer(n - i)) {
        return {i, n - i};
      }
    }
    return {};
  }

 private:
  bool is_no_zero_integer(int n) {
    while (n > 0) {
      if (n % 10 == 0) {
        return false;
      }
      n /= 10;
    }
    return true;
  }
};
