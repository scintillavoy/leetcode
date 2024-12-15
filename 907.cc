#include <stack>
#include <vector>
using namespace std;

#define MOD 1'000'000'007;

class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    int sum_of_mins = 0;
    stack<int> stk;
    for (int i = 0; i <= arr.size(); ++i) {
      while (!stk.empty() && (i == arr.size() || arr[stk.top()] >= arr[i])) {
        int t = stk.top();
        stk.pop();
        int left = t - (stk.empty() ? -1 : stk.top());
        int right = i - t;
        sum_of_mins = (sum_of_mins + (long long)arr[t] * left * right) % MOD;
      }
      stk.push(i);
    }
    return sum_of_mins;
  }
};
