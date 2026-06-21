class Solution {
 public:
  int countDigits(int num) {
    int count = 0;
    int num2 = num;
    while (num2 > 0) {
      if (num % (num2 % 10) == 0) {
        ++count;
      }
      num2 /= 10;
    }
    return count;
  }
};
