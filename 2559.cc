#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> vowelStrings(vector<string>& words,
                           vector<vector<int>>& queries) {
    vector<int> prefix_sum(words.size() + 1);
    for (int i = 0; i < words.size(); ++i) {
      prefix_sum[i + 1] = prefix_sum[i];
      if (is_vowel(words[i].front()) && is_vowel(words[i].back())) {
        ++prefix_sum[i + 1];
      }
    }
    vector<int> result(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      result[i] = prefix_sum[queries[i][1] + 1] - prefix_sum[queries[i][0]];
    }
    return result;
  }

 private:
  bool is_vowel(char c) {
    switch (c) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        return true;
      default:
        return false;
    }
  }
};
