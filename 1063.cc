#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  int validSubarrays(vector<int>& nums) {
    int result = 0;
    stack<int> stk;
    for (int i = 0; i < nums.size(); ++i) {
      while (!stk.empty() && nums[stk.top()] > nums[i]) {
        result += i - stk.top();
        stk.pop();
      }
      stk.push(i);
    }
    while (!stk.empty()) {
      result += nums.size() - stk.top();
      stk.pop();
    }
    return result;
  }
};
