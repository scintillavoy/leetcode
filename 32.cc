#include <algorithm>
#include <stack>
#include <string>
#include <utility>
using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    stack<pair<int, int>> stk;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i - 1] != '(' || s[i] != ')') {
        continue;
      }
      int start = i - 1;
      int end = i;
      while (true) {
        int start2 = start;
        int end2 = end;
        while (!stk.empty() && stk.top().second == start2 - 1) {
          start2 = stk.top().first;
          stk.pop();
        }
        while (0 <= start2 - 1 && s[start2 - 1] == '(' && end2 + 1 < s.size() &&
               s[end2 + 1] == ')') {
          --start2;
          ++end2;
        }
        if (start == start2 && end == end2) {
          break;
        }
        start = start2;
        end = end2;
      }
      stk.push({start, end});
    }
    int longest = 0;
    while (!stk.empty()) {
      longest = max(longest, stk.top().second - stk.top().first + 1);
      stk.pop();
    }
    return longest;
  }
};
