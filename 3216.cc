#include <string>
#include <utility>
using namespace std;

class Solution {
 public:
  string getSmallestString(string s) {
    for (int i = 1; i < s.size(); ++i) {
      if ((s[i - 1] - '0') % 2 == (s[i] - '0') % 2 && s[i - 1] > s[i]) {
        swap(s[i - 1], s[i]);
        break;
      }
    }
    return s;
  }
};
