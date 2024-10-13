#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;
    int max_value = numeric_limits<int>::min();
    for (int i = 0; i < nums.size(); ++i) {
      pq.push({nums[i][0], i, 0});
      max_value = max(max_value, nums[i][0]);
    }
    vector<int> smallest_range = {get<0>(pq.top()), max_value};
    while (true) {
      auto [_, i, j] = pq.top();
      pq.pop();
      if (nums[i].size() <= j + 1) {
        break;
      }
      pq.push({nums[i][j + 1], i, j + 1});
      max_value = max(max_value, nums[i][j + 1]);
      vector<int> current_range = {get<0>(pq.top()), max_value};
      if (current_range[1] - current_range[0] <
          smallest_range[1] - smallest_range[0]) {
        smallest_range = current_range;
      }
    }
    return smallest_range;
  }
};
