#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> counts;
    for (const auto c : p) {
      ++counts[c];
    }
    vector<int> result;
    int start = 0;
    for (int end = 0; end < s.size(); ++end) {
      --counts[s[end]];
      if (counts[s[end]] == 0 && end - start + 1 == p.size()) {
        result.push_back(start);
        ++counts[s[start]];
        ++start;
      }
      while (counts[s[end]] < 0) {
        ++counts[s[start]];
        ++start;
      }
    }
    return result;
  }
};
