#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    auto comp = [&](int a, int b) {
      if (nums[a] != nums[b]) {
        return nums[a] > nums[b];
      }
      return a > b;
    };
    priority_queue<int, vector<int>, decltype(comp)> pq(comp);
    for (int i = 0; i < nums.size(); ++i) {
      pq.push(i);
    }
    for (int i = 0; i < k; ++i) {
      int top_index = pq.top();
      pq.pop();
      nums[top_index] *= multiplier;
      pq.push(top_index);
    }
    return nums;
  }
};
