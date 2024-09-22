#include <algorithm>
using namespace std;

class Solution {
 public:
  int findKthNumber(int n, int k) {
    int curr = 1;
    --k;
    while (k > 0) {
      int steps = 0;
      long long prefix1 = curr;
      long long prefix2 = curr + 1;
      while (prefix1 <= n) {
        steps += min((long long)n + 1, prefix2) - prefix1;
        prefix1 *= 10;
        prefix2 *= 10;
      }
      if (steps <= k) {
        ++curr;
        k -= steps;
      } else {
        curr *= 10;
        --k;
      }
    }
    return curr;
  }
};
