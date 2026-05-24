#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> word_set(wordDict.begin(), wordDict.end());
    vector<bool> possible(s.size() + 1);
    possible[0] = true;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j <= i; ++j) {
        if (!possible[j]) {
          continue;
        }
        if (word_set.contains(s.substr(j, i - j + 1))) {
          possible[i + 1] = true;
        }
      }
    }
    return possible.back();
  }
};
