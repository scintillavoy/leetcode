#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  bool hasSpecialSubstring(string s, int k) {
    unordered_map<char, int> counts;
    for (int right = 0; right < s.size(); ++right) {
      ++counts[s[right]];
      if (right >= k - 1) {
        int left = right - k + 1;
        if (counts.size() == 1 &&
            (left - 1 < 0 || s[left - 1] != counts.begin()->first) &&
            (right + 1 >= s.size() || s[right + 1] != counts.begin()->first)) {
          return true;
        }
        --counts[s[left]];
        if (counts[s[left]] == 0) {
          counts.erase(s[left]);
        }
      }
    }
    return false;
  }
};
