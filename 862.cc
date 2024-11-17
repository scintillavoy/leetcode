#include <algorithm>
#include <deque>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> prefix_sums(n + 1);
    for (int i = 1; i <= n; ++i) {
      prefix_sums[i] = prefix_sums[i - 1] + nums[i - 1];
    }
    deque<int> candidate_indices;
    int min_length = numeric_limits<int>::max();
    for (int i = 0; i <= n; ++i) {
      while (!candidate_indices.empty() &&
             prefix_sums[i] - prefix_sums[candidate_indices.front()] >= k) {
        min_length = min(min_length, i - candidate_indices.front());
        candidate_indices.pop_front();
      }
      while (!candidate_indices.empty() &&
             prefix_sums[candidate_indices.back()] >= prefix_sums[i]) {
        candidate_indices.pop_back();
      }
      candidate_indices.push_back(i);
    }
    return min_length == numeric_limits<int>::max() ? -1 : min_length;
  }
};
