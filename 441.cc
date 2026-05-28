class Solution {
 public:
  int arrangeCoins(int n) {
    int low = 1;
    int high = n;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      long long num_of_required_coins = (long long)mid * (mid + 1) / 2;
      if (n < num_of_required_coins) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return low - 1;
  }
};
