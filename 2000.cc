#include <algorithm>
#include <string>
using namespace std;

class Solution {
 public:
  string reversePrefix(string word, char ch) {
    for (auto it = word.begin(); it != word.end(); ++it) {
      if (*it == ch) {
        reverse(word.begin(), it + 1);
        break;
      }
    }
    return word;
  }
};
