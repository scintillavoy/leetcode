class Solution {
 public:
  int minOperations(int n) {
    int count = 0;
    for (int i = 0; n != 0; ++i) {
      if ((n & (1 << i)) != 0) {
        ++count;
        if ((n & (1 << (i + 1))) != 0) {
          n += (1 << i);
        } else {
          n -= (1 << i);
        }
      }
    }
    return count;
  }
};
