#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> counts;
    for (const auto c : s1) {
      ++counts[c];
    }
    int start = 0;
    for (int end = 0; end < s2.size(); ++end) {
      --counts[s2[end]];
      if (counts[s2[end]] == 0 && end - start + 1 == s1.size()) {
        return true;
      }
      while (counts[s2[end]] < 0) {
        ++counts[s2[start]];
        ++start;
      }
    }
    return false;
  }
};
