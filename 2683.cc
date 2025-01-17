#include <vector>
using namespace std;

class Solution {
 public:
  bool doesValidArrayExist(vector<int>& derived) {
    int xor_bit = 0;
    for (const auto bit : derived) {
      xor_bit ^= bit;
    }
    return xor_bit == 0;
  }
};
