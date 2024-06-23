#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int numberOfSpecialSubstrings(string s) {
    vector<bool> exist(26);
    int start = 0;
    int result = 0;
    for (int end = 0; end < s.size(); ++end) {
      while (exist[s[end] - 'a']) {
        exist[s[start] - 'a'] = false;
        ++start;
      }
      exist[s[end] - 'a'] = true;
      result += end - start + 1;
    }
    return result;
  }
};
