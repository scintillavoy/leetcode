#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> maximumLengthOfRanges(vector<int>& nums) {
    vector<int> result(nums.size());
    stack<int> stk;
    for (int i = 0; i <= nums.size(); ++i) {
      while (!stk.empty() && (i == nums.size() || nums[stk.top()] <= nums[i])) {
        int t = stk.top();
        stk.pop();
        result[t] = i - (stk.empty() ? 0 : stk.top() + 1);
      }
      stk.push(i);
    }
    return result;
  }
};
