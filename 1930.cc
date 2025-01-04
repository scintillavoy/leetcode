#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int countPalindromicSubsequence(string s) {
    vector<int> leftmost_indexes(26, -1);
    vector<int> rightmost_indexes(26, -1);
    for (int i = 0; i < s.size(); ++i) {
      if (leftmost_indexes[s[i] - 'a'] == -1) {
        leftmost_indexes[s[i] - 'a'] = i;
      }
      rightmost_indexes[s[i] - 'a'] = i;
    }
    int result = 0;
    for (int i = 0; i < leftmost_indexes.size(); ++i) {
      if (leftmost_indexes[i] + 1 >= rightmost_indexes[i]) {
        continue;
      }
      unordered_set<char> characters;
      for (int j = leftmost_indexes[i] + 1; j < rightmost_indexes[i]; ++j) {
        characters.insert(s[j]);
      }
      result += characters.size();
    }
    return result;
  }
};
