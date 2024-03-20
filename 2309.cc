#include <cctype>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string greatestLetter(string s) {
    vector<bool> lower(26), upper(26);
    for (const auto &c : s) {
      if (islower(c)) {
        lower[c - 'a'] = true;
      } else if (isupper(c)) {
        upper[c - 'A'] = true;
      }
    }
    for (int i = 26; i > 0; --i) {
      if (lower[i - 1] && upper[i - 1]) {
        return string(1, 'A' + i - 1);
      }
    }
    return "";
  }
};
