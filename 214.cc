#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string shortestPalindrome(string s) {
    string reversed = string(s.rbegin(), s.rend());
    string combined = s + "#" + reversed;
    vector<int> kmp_table(combined.size());
    for (int i = 1, j = 0; i < combined.size(); ++i) {
      while (j > 0 && combined[i] != combined[j]) {
        j = kmp_table[j - 1];
      }
      if (combined[i] == combined[j]) {
        ++j;
      }
      kmp_table[i] = j;
    }
    return reversed.substr(0, s.size() - kmp_table.back()) + s;
  }
};
