#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  int longestPalindrome(string s) {
    unordered_set<char> char_set;
    int result = 0;
    for (const char c : s) {
      if (char_set.count(c) != 0) {
        char_set.erase(c);
        result += 2;
      } else {
        char_set.insert(c);
      }
    }
    if (!char_set.empty()) {
      ++result;
    }
    return result;
  }
};
