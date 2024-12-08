#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxTwoEvents(vector<vector<int>> &events) {
    auto comp = [](const vector<int> &a, const vector<int> &b) {
      return a[2] < b[2];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(
        events.begin(), events.end());
    sort(
        events.begin(), events.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });
    int max_sum = 0;
    for (const auto &event : events) {
      while (!pq.empty() && pq.top()[0] <= event[1]) {
        pq.pop();
      }
      int sum = event[2];
      if (!pq.empty()) {
        sum += pq.top()[2];
      }
      max_sum = max(max_sum, sum);
    }
    return max_sum;
  }
};
