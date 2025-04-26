#include <string>
using namespace std;

class Solution {
 public:
  int balancedStringSplit(string s) {
    int result = 0;
    int count = 0;
    for (const auto c : s) {
      if (c == 'L') {
        ++count;
      } else {
        --count;
      }
      if (count == 0) {
        ++result;
      }
    }
    return result;
  }
};
