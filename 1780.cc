class Solution {
 public:
  bool checkPowersOfThree(int n) {
    int power_of_three = 1;
    while (power_of_three * 3 <= n) {
      power_of_three *= 3;
    }
    while (power_of_three > 0) {
      if (n >= power_of_three) {
        n -= power_of_three;
      }
      if (n == 0) {
        return true;
      }
      power_of_three /= 3;
    }
    return false;
  }
};
