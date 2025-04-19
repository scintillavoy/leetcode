#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int countCharacters(vector<string>& words, string chars) {
    int result = 0;
    vector<int> available_counts(26);
    for (const auto c : chars) {
      ++available_counts[c - 'a'];
    }
    for (const auto& word : words) {
      vector<int> counts(26);
      for (const auto c : word) {
        ++counts[c - 'a'];
        if (counts[c - 'a'] > available_counts[c - 'a']) {
          goto outer_loop;
        }
      }
      result += word.size();
    outer_loop:
    }
    return result;
  }
};
