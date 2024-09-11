class Solution {
 public:
  int minBitFlips(int start, int goal) {
    int count = 0;
    while (start > 0 || goal > 0) {
      count += (start & 1) ^ (goal & 1);
      start >>= 1;
      goal >>= 1;
    }
    return count;
  }
};
