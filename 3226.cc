class Solution {
 public:
  int minChanges(int n, int k) {
    if ((n | k) != n) {
      return -1;
    }
    int mask = n ^ k;
    int count = 0;
    while (mask > 0) {
      mask &= mask - 1;
      ++count;
    }
    return count;
  }
};
