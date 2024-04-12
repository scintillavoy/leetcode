#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    int answer = 0;
    stack<int> stk;
    for (int i = 0; i < height.size(); ++i) {
      while (!stk.empty() && height[stk.top()] <= height[i]) {
        int t = stk.top();
        stk.pop();
        if (stk.empty()) {
          break;
        }
        answer += (i - stk.top() - 1) *
                  (min(height[i], height[stk.top()]) - height[t]);
      }
      stk.push(i);
    }
    return answer;
  }
};
