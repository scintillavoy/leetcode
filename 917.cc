#include <cctype>
#include <string>
#include <utility>
using namespace std;

class Solution {
 public:
  string reverseOnlyLetters(string s) {
    int start = 0;
    int end = s.size() - 1;
    while (start < end) {
      while (start < end && !isalpha(s[start])) {
        ++start;
      }
      while (start < end && !isalpha(s[end])) {
        --end;
      }
      if (start >= end) {
        break;
      }
      swap(s[start], s[end]);
      ++start;
      --end;
    }
    return s;
  }
};
