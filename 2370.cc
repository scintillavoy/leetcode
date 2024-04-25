#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestIdealString(string s, int k) {
    vector<int> lengths(26);
    for (int i = 0; i < s.size(); ++i) {
      int max_length = 1;
      for (int j = s[i] - 'a' - k; j <= s[i] - 'a' + k; ++j) {
        if (j < 0 || j >= 26) {
          continue;
        }
        max_length = max(max_length, lengths[j] + 1);
      }
      lengths[s[i] - 'a'] = max_length;
    }
    return *max_element(lengths.cbegin(), lengths.cend());
  }
};
