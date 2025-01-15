#include <cmath>
using namespace std;

class Solution {
 public:
  int minimizeXor(int num1, int num2) {
    int bit_count1 = count_num_of_set_bits(num1);
    int bit_count2 = count_num_of_set_bits(num2);
    if (bit_count1 == bit_count2) {
      return num1;
    }
    int count_diff = abs(bit_count1 - bit_count2);
    int x = num1;
    int mask = 1;
    if (bit_count1 < bit_count2) {
      while (count_diff > 0) {
        if ((num1 & mask) == 0) {
          x |= mask;
          --count_diff;
        }
        mask <<= 1;
      }
    } else {
      while (count_diff > 0) {
        if ((num1 & mask) != 0) {
          x &= ~mask;
          --count_diff;
        }
        mask <<= 1;
      }
    }
    return x;
  }

 private:
  int count_num_of_set_bits(int num) {
    int bit_count = 0;
    while (num > 0) {
      if ((num & 1) == 1) {
        ++bit_count;
      }
      num >>= 1;
    }
    return bit_count;
  }
};
