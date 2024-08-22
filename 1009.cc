class Solution {
 public:
  int bitwiseComplement(int n) {
    if (n == 0) {
      return 1;
    }
    int ones = 0;
    for (int temp = n; temp > 0; temp >>= 1) {
      ones = (ones << 1) | 1;
    }
    return n ^ ones;
  }
};
