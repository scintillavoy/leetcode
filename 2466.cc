#include <vector>
using namespace std;

#define MOD 1'000'000'007

class Solution {
 public:
  int countGoodStrings(int low, int high, int zero, int one) {
    vector<int> counts(high + 1);
    counts[0] = 1;
    int sum = 0;
    for (int i = 1; i <= high; ++i) {
      if (i >= zero) {
        counts[i] = (counts[i] + counts[i - zero]) % MOD;
      }
      if (i >= one) {
        counts[i] = (counts[i] + counts[i - one]) % MOD;
      }
      if (i >= low) {
        sum = (sum + counts[i]) % MOD;
      }
    }
    return sum;
  }
};
