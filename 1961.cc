#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isPrefixString(string s, vector<string>& words) {
    int s_index = 0;
    for (const auto& word : words) {
      for (int i = 0; i < word.size(); ++i) {
        if (s_index >= s.size() || s[s_index] != word[i]) {
          return false;
        }
        ++s_index;
      }
      if (s_index == s.size()) {
        return true;
      }
    }
    return false;
  }
};
