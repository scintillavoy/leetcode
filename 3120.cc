#include <cctype>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int numberOfSpecialChars(string word) {
    vector<bool> lowercases(26);
    vector<bool> uppercases(26);
    for (const auto c : word) {
      if (islower(c)) {
        lowercases[c - 'a'] = true;
      } else {
        uppercases[c - 'A'] = true;
      }
    }
    int result = 0;
    for (int i = 0; i < lowercases.size(); ++i) {
      if (lowercases[i] && uppercases[i]) {
        ++result;
      }
    }
    return result;
  }
};
