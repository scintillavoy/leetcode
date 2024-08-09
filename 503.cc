#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> result(nums.size());
    stack<int> stk;
    for (int i = 2 * nums.size() - 1; i >= 0; --i) {
      while (!stk.empty() && nums[i % nums.size()] >= stk.top()) {
        stk.pop();
      }
      result[i % nums.size()] = stk.empty() ? -1 : stk.top();
      stk.push(nums[i % nums.size()]);
    }
    return result;
  }
};
