#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string reverseParentheses(string s) {
    vector<int> pairs(s.size());
    stack<int> indices;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        indices.push(i);
      } else if (s[i] == ')') {
        pairs[i] = indices.top();
        pairs[indices.top()] = i;
        indices.pop();
      }
    }
    string result;
    for (int i = 0, direction = 1; i < s.size(); i += direction) {
      if (s[i] == '(' || s[i] == ')') {
        i = pairs[i];
        direction *= -1;
      } else {
        result += s[i];
      }
    }
    return result;
  }
};
