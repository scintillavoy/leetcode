#include <algorithm>
#include <string>
using namespace std;

class Solution {
 public:
  int longestContinuousSubstring(string s) {
    int max_length = 0;
    int start = 0;
    for (int end = 1; end <= s.size(); ++end) {
      if (end == s.size() || s[end - 1] + 1 != s[end]) {
        max_length = max(max_length, end - start);
        start = end;
      }
    }
    return max_length;
  }
};
