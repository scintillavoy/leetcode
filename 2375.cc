#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  string smallestNumber(string pattern) {
    string smallest_number;
    stack<int> stk;
    for (int i = 0; i <= pattern.size(); ++i) {
      stk.push(i + 1);
      if (i == pattern.size() || pattern[i] == 'I') {
        while (!stk.empty()) {
          smallest_number.push_back(stk.top() + '0');
          stk.pop();
        }
      }
    }
    return smallest_number;
  }
};
