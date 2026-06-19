#include <string>
using namespace std;

class Solution {
 public:
  char processStr(string s, long long k) {
    long long length = 0;
    for (const auto c : s) {
      if (c == '*') {
        if (length > 0) {
          --length;
        }
      } else if (c == '#') {
        length *= 2;
      } else if (c == '%') {
        continue;
      } else {
        ++length;
      }
    }
    if (k >= length) {
      return '.';
    }
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] == '*') {
        ++length;
      } else if (s[i] == '#') {
        if (k >= length / 2) {
          k -= length / 2;
        }
        length /= 2;
      } else if (s[i] == '%') {
        k = length - k - 1;
      } else {
        if (k + 1 == length) {
          return s[i];
        }
        --length;
      }
    }
    return '.';
  }
};
