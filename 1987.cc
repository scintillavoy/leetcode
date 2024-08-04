#include <string>
using namespace std;

#define MOD 1'000'000'007

class Solution {
 public:
  int numberOfUniqueGoodSubsequences(string binary) {
    int total = 1;
    int good = 0;
    int last_zero = 0;
    int last_one = 0;
    bool has_zero = false;
    for (int i = binary.size() - 1; i >= 0; --i) {
      int prev_total = total;
      if (binary[i] == '0') {
        total = (total * 2 % MOD + MOD - last_zero) % MOD;
        last_zero = prev_total;
        has_zero = true;
      } else {
        total = (total * 2 % MOD + MOD - last_one) % MOD;
        last_one = prev_total;
        good += total - prev_total;
        if (good < 0) {
          good += MOD;
        }
        good %= MOD;
      }
    }
    if (has_zero) {
      ++good;
    }
    return good;
  }
};
