#include <algorithm>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    int n = quality.size();
    vector<pair<double, int>> wage_to_quality;
    for (int i = 0; i < n; ++i) {
      wage_to_quality.push_back({(double)wage[i] / quality[i], quality[i]});
    }
    sort(wage_to_quality.begin(), wage_to_quality.end());

    priority_queue<int> pq;
    int total_quality = 0;
    double min_cost = numeric_limits<double>::max();
    for (int i = 0; i < n; ++i) {
      pq.push(wage_to_quality[i].second);
      total_quality += wage_to_quality[i].second;
      if (pq.size() > k) {
        total_quality -= pq.top();
        pq.pop();
      }
      if (pq.size() == k) {
        min_cost = min(min_cost, total_quality * wage_to_quality[i].first);
      }
    }

    return min_cost;
  }
};
