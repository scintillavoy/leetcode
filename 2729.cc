#include <vector>
using namespace std;

class Solution {
 public:
  bool isFascinating(int n) {
    vector<int> counts(10);
    check(n, counts);
    check(2 * n, counts);
    check(3 * n, counts);
    if (counts[0] != 0) {
      return false;
    }
    for (int i = 1; i < 10; ++i) {
      if (counts[i] != 1) {
        return false;
      }
    }
    return true;
  }

 private:
  void check(int n, vector<int> &counts) {
    while (n > 0) {
      ++counts[n % 10];
      n /= 10;
    }
  }
};
