#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    stack<int> stk;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        stk.push(i);
      } else if (s[i] == ')') {
        if (stk.empty()) {
          s[i] = '#';
        } else {
          stk.pop();
        }
      }
    }
    while (!stk.empty()) {
      int curr = stk.top();
      stk.pop();
      s[curr] = '#';
    }
    string answer;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != '#') {
        answer.push_back(s[i]);
      }
    }
    return answer;
  }
};
