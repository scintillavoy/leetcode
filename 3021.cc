class Solution {
 public:
  long long flowerGame(int n, int m) {
    return (long long)((n + 1) / 2) * (m / 2) +
           (long long)(n / 2) * ((m + 1) / 2);
  }
};
