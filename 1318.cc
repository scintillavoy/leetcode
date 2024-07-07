class Solution {
 public:
  int minFlips(int a, int b, int c) {
    int a_or_b = a | b;
    int result = 0;
    for (int bit = 1; bit > 0; bit <<= 1) {
      if ((bit & a_or_b) == (bit & c)) {
        continue;
      }
      if ((bit & c) != 0) {
        ++result;
      } else {
        if ((bit & a) != 0) {
          ++result;
        }
        if ((bit & b) != 0) {
          ++result;
        }
      }
    }
    return result;
  }
};
