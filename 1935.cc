#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  int canBeTypedWords(string text, string brokenLetters) {
    unordered_set<char> letters(brokenLetters.begin(), brokenLetters.end());
    int result = 0;
    bool can_type = true;
    for (const auto c : text) {
      if (c == ' ') {
        if (can_type) {
          ++result;
        }
        can_type = true;
        continue;
      }
      if (letters.contains(c)) {
        can_type = false;
      }
    }
    if (can_type) {
      ++result;
    }
    return result;
  }
};
