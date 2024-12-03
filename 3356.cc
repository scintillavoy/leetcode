#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> possible_decrements(nums.size() + 1);
    int sum = 0;
    int query_index = 0;
    for (int i = 0; i < nums.size(); ++i) {
      while (sum + possible_decrements[i] < nums[i]) {
        if (query_index == queries.size()) {
          return -1;
        }
        int left = queries[query_index][0];
        int right = queries[query_index][1];
        int val = queries[query_index][2];
        ++query_index;
        if (right < i) {
          continue;
        }
        possible_decrements[max(left, i)] += val;
        possible_decrements[right + 1] -= val;
      }
      sum += possible_decrements[i];
    }
    return query_index;
  }
};
