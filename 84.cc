#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int max_area = 0;
    stack<int> stk;
    for (int i = 0; i < heights.size(); ++i) {
      while (!stk.empty() && heights[stk.top()] >= heights[i]) {
        int t = stk.top();
        stk.pop();
        int height = heights[t];
        int width = i - (stk.empty() ? 0 : stk.top() + 1);
        max_area = max(max_area, height * width);
      }
      stk.push(i);
    }
    while (!stk.empty()) {
      int t = stk.top();
      stk.pop();
      int height = heights[t];
      int width = heights.size() - (stk.empty() ? 0 : stk.top() + 1);
      max_area = max(max_area, height * width);
    }
    return max_area;
  }
};
