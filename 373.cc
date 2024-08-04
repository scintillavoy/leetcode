#include <functional>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;
    for (int i = 0; i < nums1.size(); ++i) {
      pq.push({nums1[i] + nums2[0], i, 0});
    }
    vector<vector<int>> result;
    while (result.size() < k) {
      auto [_, i, j] = pq.top();
      pq.pop();
      result.push_back({nums1[i], nums2[j]});
      if (j + 1 < nums2.size()) {
        pq.push({nums1[i] + nums2[j + 1], i, j + 1});
      }
    }
    return result;
  }
};
