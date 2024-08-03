#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int start = 0, end = 0;
    int max_length = 0;
    while (end < s.size()) {
      while (end < s.size() && seen.count(s[end]) == 0) {
        seen.insert(s[end]);
        ++end;
      }
      max_length = max(max_length, end - start);
      seen.erase(s[start]);
      ++start;
    }
    return max_length;
  }
};
