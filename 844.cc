#include <algorithm>
#include <string>
using namespace std;

class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    int s_size = process(s);
    int t_size = process(t);
    if (s_size != t_size) {
      return false;
    }
    for (int i = 0; i < s_size; ++i) {
      if (s[i] != t[i]) {
        return false;
      }
    }
    return true;
  }

 private:
  int process(string &s) {
    int next = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '#') {
        next = max(0, next - 1);
      } else {
        s[next] = s[i];
        ++next;
      }
    }
    return next;
  }
};
