#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  bool wordPatternMatch(string pattern, string s) {
    string word;
    return backtrack(pattern, s, word, 0, 0);
  }

 private:
  unordered_map<char, string> pattern_to_s;
  unordered_map<string, char> s_to_pattern;

  bool backtrack(string &pattern, string &s, string &token, int idx1,
                 int idx2) {
    if (idx1 == pattern.size() && idx2 == s.size()) {
      return true;
    } else if (idx1 == pattern.size() || idx2 == s.size()) {
      return false;
    }
    token.push_back(s[idx2]);
    if ((pattern_to_s.count(pattern[idx1]) == 0 &&
         s_to_pattern.count(token) == 0) ||
        (pattern_to_s.count(pattern[idx1]) == 1 &&
         pattern_to_s[pattern[idx1]] == token)) {
      bool should_map = false;
      if (pattern_to_s.count(pattern[idx1]) == 0) {
        should_map = true;
      }
      if (should_map) {
        pattern_to_s[pattern[idx1]] = token;
        s_to_pattern[token] = pattern[idx1];
      }
      string new_word;
      if (backtrack(pattern, s, new_word, idx1 + 1, idx2 + 1)) {
        return true;
      }
      if (should_map) {
        pattern_to_s.erase(pattern[idx1]);
        s_to_pattern.erase(token);
      }
    }
    return backtrack(pattern, s, token, idx1, idx2 + 1);
  }
};
