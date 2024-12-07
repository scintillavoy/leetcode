#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
    sort(queries.begin(), queries.end());
    priority_queue<int> pq;
    vector<int> decrements(nums.size() + 1);
    int max_removal = 0;
    int query_index = 0;
    for (int num_index = 0; num_index < nums.size(); ++num_index) {
      if (nums[num_index] > decrements[num_index]) {
        while (query_index < queries.size() &&
               queries[query_index][0] <= num_index) {
          pq.push(queries[query_index][1]);
          ++query_index;
        }
        while (nums[num_index] > decrements[num_index]) {
          if (pq.empty()) {
            return -1;
          }
          int right = pq.top();
          pq.pop();
          if (right < num_index) {
            ++max_removal;
            continue;
          }
          ++decrements[num_index];
          --decrements[right + 1];
        }
      }
      decrements[num_index + 1] += decrements[num_index];
    }
    max_removal += pq.size() + queries.size() - query_index;
    return max_removal;
  }
};
