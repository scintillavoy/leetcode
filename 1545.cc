class Solution {
 public:
  char findKthBit(int n, int k) {
    if (n == 1) {
      return '0';
    }
    int total_length = (1 << n) - 1;
    if (k - 1 == total_length / 2) {
      return '1';
    }
    if (k - 1 < total_length / 2) {
      return findKthBit(n - 1, k);
    }
    return flip(findKthBit(n - 1, total_length - k + 1));
  }

 private:
  char flip(char bit) { return bit == '0' ? '1' : '0'; }
};
