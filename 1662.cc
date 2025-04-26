#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    while (i < word1.size() && k < word2.size()) {
      if (word1[i][j] != word2[k][l]) {
        return false;
      }
      ++j;
      if (j == word1[i].size()) {
        ++i;
        j = 0;
      }
      ++l;
      if (l == word2[k].size()) {
        ++k;
        l = 0;
      }
    }
    return i == word1.size() && k == word2.size();
  }
};
