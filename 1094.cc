#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    for (const auto& trip : trips) {
      pq.push({trip[1], trip[0]});
      pq.push({trip[2], -trip[0]});
    }
    int current = 0;
    while (!pq.empty()) {
      current += pq.top().second;
      pq.pop();
      if (current > capacity) {
        return false;
      }
    }
    return true;
  }
};
