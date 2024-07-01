#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool closeStrings(string word1, string word2) {
    vector<int> counts1(26);
    for (const auto c : word1) {
      ++counts1[c - 'a'];
    }
    vector<int> counts2(26);
    for (const auto c : word2) {
      ++counts2[c - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
      if ((counts1[i] != 0 && counts2[i] == 0) ||
          (counts1[i] == 0 && counts2[i] != 0)) {
        return false;
      }
    }
    sort(counts1.begin(), counts1.end());
    sort(counts2.begin(), counts2.end());
    for (int i = 0; i < 26; ++i) {
      if (counts1[i] != counts2[i]) {
        return false;
      }
    }
    return true;
  }
};
