#include <limits>
using namespace std;

// Review required
class Solution {
 public:
  int reverse(int x) {
    int rev = 0;
    while (x != 0) {
      if (rev > numeric_limits<int>::max() / 10 ||
          rev == numeric_limits<int>::max() / 10 && x % 10 > 7 ||
          rev < numeric_limits<int>::min() / 10 ||
          rev == numeric_limits<int>::min() / 10 && x % 10 < -8) {
        return 0;
      }
      rev = rev * 10 + x % 10;
      x /= 10;
    }
    return rev;
  }
};

int main() { return 0; }
