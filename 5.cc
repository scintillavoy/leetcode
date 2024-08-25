#include <string>
using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    int longest_left = 0, longest_right = 0;
    for (int i = 0; i < s.size(); ++i) {
      expand(i, i, s, longest_left, longest_right);
      expand(i, i + 1, s, longest_left, longest_right);
    }
    return s.substr(longest_left, longest_right - longest_left + 1);
  }

 private:
  void expand(int left, int right, const string &s, int &longest_left,
              int &longest_right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      --left;
      ++right;
    }
    if (right - left - 1 > longest_right - longest_left + 1) {
      longest_left = left + 1;
      longest_right = right - 1;
    }
  }
};
