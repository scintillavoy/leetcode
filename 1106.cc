#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool parseBoolExpr(string expression) {
    stack<char> stk;
    for (const auto c : expression) {
      if (c == ')') {
        vector<char> values;
        while (stk.top() != '(') {
          values.push_back(stk.top());
          stk.pop();
        }
        stk.pop();
        char op = stk.top();
        stk.pop();
        switch (op) {
          case '!':
            stk.push(values[0] != 't' ? 't' : 'f');
            break;
          case '&': {
            bool result = true;
            for (const auto value : values) {
              result = result && (value == 't');
            }
            stk.push(result ? 't' : 'f');
            break;
          }
          case '|': {
            bool result = false;
            for (const auto value : values) {
              result = result || (value == 't');
            }
            stk.push(result ? 't' : 'f');
            break;
          }
        }
      } else {
        switch (c) {
          case 't':
          case 'f':
          case '!':
          case '&':
          case '|':
          case '(':
            stk.push(c);
            break;
        }
      }
    }
    return stk.top() == 't';
  }
};
