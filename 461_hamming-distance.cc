class Solution {
 public:
  int hammingDistance(int x, int y) {
    int dist = 0;
    int n = x ^ y;
    while (n != 0) {
      n &= n - 1;
      ++dist;
    }
    return dist;
  }
};

int main() { return 0; }
