#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int countPrefixes(vector<string>& words, string s) {
    int num_of_prefixes = 0;
    for (const auto& word : words) {
      int i = 0;
      int j = 0;
      while (i < word.size() && j < s.size()) {
        if (word[i] != s[j]) {
          break;
        }
        ++i;
        ++j;
      }
      if (i == word.size()) {
        ++num_of_prefixes;
      }
    }
    return num_of_prefixes;
  }
};
