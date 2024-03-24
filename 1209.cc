#include <algorithm>
#include <stack>
#include <string>
#include <utility>
using namespace std;

class Solution {
 public:
  string removeDuplicates(string s, int k) {
    string answer;
    stack<pair<char, int>> stk;
    for (int i = 0; i < s.size(); ++i) {
      if (!stk.empty() && stk.top().first == s[i]) {
        if (stk.top().second + 1 == k) {
          for (int j = 0; j < k - 1; ++j) {
            stk.pop();
          }
        } else {
          stk.push({s[i], stk.top().second + 1});
        }
      } else {
        stk.push({s[i], 1});
      }
    }
    while (!stk.empty()) {
      answer.push_back(stk.top().first);
      stk.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};
