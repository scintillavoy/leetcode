#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    unordered_map<char, char> bracket_pairs{{')', '('}, {']', '['}, {'}', '{'}};
    stack<char> stk;
    for (const auto c : s) {
      switch (c) {
        case '(':
        case '[':
        case '{':
          stk.push(c);
          break;
        case ')':
        case ']':
        case '}':
          if (stk.empty() || stk.top() != bracket_pairs[c]) {
            return false;
          }
          stk.pop();
          break;
      }
    }
    return stk.empty();
  }
};
