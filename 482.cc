#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

class Solution {
 public:
  string licenseKeyFormatting(string s, int k) {
    string formatted;
    int count = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] == '-') {
        continue;
      }
      if (count == k) {
        formatted += '-';
        count = 0;
      }
      formatted += toupper(s[i]);
      ++count;
    }
    reverse(formatted.begin(), formatted.end());
    return formatted;
  }
};
