class Solution {
 public:
  int smallestNumber(int n) {
    int result = 1;
    while (result < n) {
      result = (result << 1) + 1;
    }
    return result;
  }
};
