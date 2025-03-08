#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int numKLenSubstrNoRepeats(string s, int k) {
    vector<int> counts(26);
    int result = 0;
    int num_of_repeated_characters = 0;
    for (int i = 0; i < s.size(); ++i) {
      ++counts[s[i] - 'a'];
      if (counts[s[i] - 'a'] == 2) {
        ++num_of_repeated_characters;
      }
      if (i >= k - 1) {
        if (num_of_repeated_characters == 0) {
          ++result;
        }
        --counts[s[i - k + 1] - 'a'];
        if (counts[s[i - k + 1] - 'a'] == 1) {
          --num_of_repeated_characters;
        }
      }
    }
    return result;
  }
};
