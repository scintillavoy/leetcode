#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    for (const auto num : nums) {
      ++counts[num];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    for (const auto [num, count] : counts) {
      if (pq.size() < k) {
        pq.push({count, num});
        continue;
      }
      if (pq.top().first < count) {
        pq.pop();
        pq.push({count, num});
      }
    }
    vector<int> result(k);
    for (int i = 0; i < k; ++i) {
      result[i] = pq.top().second;
      pq.pop();
    }
    return result;
  }
};
