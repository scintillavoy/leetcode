#include <string>
using namespace std;

class Solution {
 public:
  string truncateSentence(string s, int k) {
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
        --k;
        if (k == 0) {
          while (i < s.size()) {
            s.pop_back();
          }
          return s;
        }
      }
    }
    return s;
  }
};
