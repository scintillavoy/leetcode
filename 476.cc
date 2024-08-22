class Solution {
 public:
  int findComplement(int num) {
    int ones = 0;
    for (int temp = num; temp > 0; temp >>= 1) {
      ones = (ones << 1) | 1;
    }
    return num ^ ones;
  }
};
