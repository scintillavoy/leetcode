#define MOD 1'000'000'007

class Solution {
 public:
  int countGoodNumbers(long long n) {
    long long result = 1;
    if (n % 2 == 1) {
      result = 5;
    }
    n /= 2;
    long long base = 20;
    while (n > 0) {
      if (n % 2 == 1) {
        result = (result * base) % MOD;
      }
      base = (base * base) % MOD;
      n /= 2;
    }
    return result;
  }
};
