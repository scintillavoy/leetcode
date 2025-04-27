#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  string findValidPair(string s) {
    unordered_map<char, int> counts;
    for (const auto c : s) {
      ++counts[c];
    }
    for (int i = 1; i < s.size(); ++i) {
      if (s[i - 1] != s[i] && counts[s[i - 1]] == s[i - 1] - '0' &&
          counts[s[i]] == s[i] - '0') {
        return s.substr(i - 1, 2);
      }
    }
    return "";
  }
};
