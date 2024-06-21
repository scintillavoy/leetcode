class Solution {
 public:
  int tribonacci(int n) {
    if (n == 0) {
      return 0;
    }
    if (n < 3) {
      return 1;
    }
    int t0 = 0, t1 = 1, t2 = 1;
    for (int i = 0; i < n - 2; ++i) {
      int t3 = t0 + t1 + t2;
      t0 = t1;
      t1 = t2;
      t2 = t3;
    }
    return t2;
  }
};
