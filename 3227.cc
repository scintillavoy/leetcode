#include <string>
using namespace std;

class Solution {
 public:
  bool doesAliceWin(string s) {
    for (const auto c : s) {
      if (is_vowel(c)) {
        return true;
      }
    }
    return false;
  }

 private:
  bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};
