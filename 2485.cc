class Solution {
 public:
  int pivotInteger(int n) {
    int left_sum = 0;
    int right_sum = n * (n + 1) / 2;
    for (int i = 1; i <= n; ++i) {
      left_sum += i;
      right_sum -= i - 1;
      if (left_sum == right_sum) {
        return i;
      }
    }
    return -1;
  }
};
