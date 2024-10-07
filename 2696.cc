#include <string>
using namespace std;

class Solution {
 public:
  int minLength(string s) {
    int i = -1;
    for (int j = 0; j < s.size(); ++j) {
      if (i >= 0 &&
          ((s[i] == 'A' && s[j] == 'B') || (s[i] == 'C' && s[j] == 'D'))) {
        --i;
      } else {
        ++i;
        s[i] = s[j];
      }
    }
    return i + 1;
  }
};
