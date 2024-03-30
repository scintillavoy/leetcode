#include <limits>
using namespace std;

class Solution {
 public:
  int reverse(int x) {
    int answer = 0;
    while (x != 0) {
      if (answer > numeric_limits<int>::max() / 10 ||
          answer < numeric_limits<int>::min() / 10) {
        return 0;
      }
      answer = answer * 10 + x % 10;
      x /= 10;
    }
    return answer;
  }
};
