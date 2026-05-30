#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> canSeePersonsCount(vector<int>& heights) {
    vector<int> result(heights.size());
    stack<int> stk;
    for (int i = heights.size() - 1; i >= 0; --i) {
      while (!stk.empty() && heights[i] > heights[stk.top()]) {
        ++result[i];
        stk.pop();
      }
      if (!stk.empty()) {
        ++result[i];
      }
      stk.push(i);
    }
    return result;
  }
};
