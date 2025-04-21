#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> evenOddBit(int n) {
    vector<int> counts(2);
    int index = 0;
    while (n > 0) {
      counts[index] += n & 1;
      index ^= 1;
      n >>= 1;
    }
    return counts;
  }
};
