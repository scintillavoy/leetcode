class Solution {
 public:
  bool checkPerfectNumber(int num) {
    int sum_of_divisors = 0;
    for (int i = 1; i * i <= num; ++i) {
      if (num % i == 0) {
        sum_of_divisors += i;
        if (i * i != num) {
          sum_of_divisors += num / i;
        }
      }
    }
    return num == sum_of_divisors - num;
  }
};
