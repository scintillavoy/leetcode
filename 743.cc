#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> graph(n + 1);
    for (const auto& time : times) {
      graph[time[0]].push_back({time[2], time[1]});
    }
    vector<int> distances(n + 1, numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    distances[k] = 0;
    pq.push({0, k});
    while (!pq.empty()) {
      auto [curr_distance, curr] = pq.top();
      pq.pop();
      if (distances[curr] < curr_distance) {
        continue;
      }
      for (const auto& [adj_weight, adj] : graph[curr]) {
        if (distances[adj] > distances[curr] + adj_weight) {
          distances[adj] = distances[curr] + adj_weight;
          pq.push({distances[adj], adj});
        }
      }
    }
    int max_distance = 0;
    for (int i = 1; i < distances.size(); ++i) {
      if (distances[i] == numeric_limits<int>::max()) {
        return -1;
      }
      max_distance = max(max_distance, distances[i]);
    }
    return max_distance;
  }
};
