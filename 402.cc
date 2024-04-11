#include <deque>
#include <string>
using namespace std;

class Solution {
 public:
  string removeKdigits(string num, int k) {
    deque<char> stk;
    for (int i = 0; i < num.size(); ++i) {
      while (!stk.empty() && k > 0 && stk.back() > num[i]) {
        stk.pop_back();
        --k;
      }
      stk.push_back(num[i]);
    }
    for (int i = 0; i < k; ++i) {
      stk.pop_back();
    }
    while (!stk.empty() && stk.front() == '0') {
      stk.pop_front();
    }
    if (stk.empty()) {
      return "0";
    }
    return string(stk.begin(), stk.end());
  }
};
