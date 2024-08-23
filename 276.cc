class Solution {
 public:
  int numWays(int n, int k) {
    if (n == 1) {
      return k;
    }
    int prev = k;
    int curr = k * k;
    for (int i = 3; i <= n; ++i) {
      int next = (prev + curr) * (k - 1);
      prev = curr;
      curr = next;
    }
    return curr;
  }
};
