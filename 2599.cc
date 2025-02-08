#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int makePrefSumNonNegative(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> candidates;
    long long prefix_sum = 0;
    int num_of_operations = 0;
    for (const auto num : nums) {
      prefix_sum += num;
      if (num < 0) {
        candidates.push(num);
      }
      while (prefix_sum < 0) {
        if (candidates.empty()) {
          return -1;
        }
        prefix_sum -= candidates.top();
        candidates.pop();
        ++num_of_operations;
      }
    }
    return num_of_operations;
  }
};
