class Solution {
 public:
  int alternateDigitSum(int n) {
    int sum = 0;
    int sum2 = 0;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
      if (n == 0) {
        return sum - sum2;
      }
      sum2 += n % 10;
      n /= 10;
    }
    return sum2 - sum;
  }
};
