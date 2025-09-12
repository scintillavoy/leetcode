#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxLengthBetweenEqualCharacters(string s) {
    vector<int> first_seen(26, -1);
    int max_length = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (first_seen[s[i] - 'a'] != -1) {
        max_length = max(max_length, i - first_seen[s[i] - 'a'] - 1);
      } else {
        first_seen[s[i] - 'a'] = i;
      }
    }
    return max_length;
  }
};
