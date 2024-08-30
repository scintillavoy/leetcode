#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumLength(string s) {
    vector<vector<int>> counts(26, vector<int>(s.size() + 1));
    int repetition = 1;
    ++counts[s[0] - 'a'][1];
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] != s[i - 1]) {
        repetition = 0;
      }
      ++repetition;
      ++counts[s[i] - 'a'][repetition];
    }
    int max_length = -1;
    for (int i = 0; i < counts.size(); ++i) {
      for (int j = s.size(); j >= 1; --j) {
        if (counts[i][j] >= 3) {
          max_length = max(max_length, j);
          break;
        }
        counts[i][j - 1] += counts[i][j];
      }
    }
    return max_length;
  }
};
