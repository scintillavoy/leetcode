#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int answer = 0;
    vector<int> height(m);
    for (int i = 0; i < n; ++i) {
      stack<int> stk;
      for (int j = 0; j < m; ++j) {
        if (matrix[i][j] == '0') {
          height[j] = 0;
        } else {
          ++height[j];
        }
        while (!stk.empty() && height[stk.top()] >= height[j]) {
          int t = stk.top();
          stk.pop();
          int width = j - (stk.empty() ? 0 : stk.top() + 1);
          answer = max(answer, height[t] * width);
        }
        stk.push(j);
      }
      while (!stk.empty()) {
        int t = stk.top();
        stk.pop();
        int width = m - (stk.empty() ? 0 : stk.top() + 1);
        answer = max(answer, height[t] * width);
      }
    }
    return answer;
  }
};
