#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  long long subArrayRanges(vector<int>& nums) {
    long long sum = 0;
    stack<int> inc, dec;
    for (int i = 0; i <= nums.size(); ++i) {
      while (!inc.empty() && (i == nums.size() || nums[inc.top()] >= nums[i])) {
        int t = inc.top();
        inc.pop();
        int left = t - (inc.empty() ? -1 : inc.top());
        int right = i - t;
        sum -= (long long)nums[t] * left * right;
      }
      while (!dec.empty() && (i == nums.size() || nums[dec.top()] <= nums[i])) {
        int t = dec.top();
        dec.pop();
        int left = t - (dec.empty() ? -1 : dec.top());
        int right = i - t;
        sum += (long long)nums[t] * left * right;
      }
      inc.push(i);
      dec.push(i);
    }
    return sum;
  }
};
