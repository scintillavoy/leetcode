#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxWidthRamp(vector<int>& nums) {
    stack<int> stk;
    for (int i = 0; i < nums.size(); ++i) {
      if (stk.empty() || nums[stk.top()] > nums[i]) {
        stk.push(i);
      }
    }
    int max_width = 0;
    for (int i = nums.size() - 1; i >= 0; --i) {
      while (!stk.empty() && nums[stk.top()] <= nums[i]) {
        max_width = max(max_width, i - stk.top());
        stk.pop();
      }
    }
    return max_width;
  }
};
