class Solution {
 public:
  int climbStairs(int n) {
    int curr = 1, next = 0, next2 = 0;
    for (int i = 1; i <= n; ++i) {
      next += curr;
      next2 = curr;
      curr = next;
      next = next2;
    }
    return curr;
  }
};
