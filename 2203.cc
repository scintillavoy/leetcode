#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2,
                          int dest) {
    vector<vector<pair<int, int>>> graph(n), graph_rev(n);
    for (const auto& edge : edges) {
      graph[edge[0]].push_back({edge[2], edge[1]});
      graph_rev[edge[1]].push_back({edge[2], edge[0]});
    }
    vector<vector<long long>> distances(
        3, vector<long long>(n, numeric_limits<long long>::max()));
    dijkstra(src1, graph, distances[0]);
    dijkstra(src2, graph, distances[1]);
    dijkstra(dest, graph_rev, distances[2]);
    long long min_weight = numeric_limits<long long>::max();
    for (int i = 0; i < n; ++i) {
      bool valid = true;
      long long weight = 0;
      for (int j = 0; j < 3; ++j) {
        if (distances[j][i] == numeric_limits<long long>::max()) {
          valid = false;
          break;
        }
        weight += distances[j][i];
      }
      if (valid) {
        min_weight = min(min_weight, weight);
      }
    }
    return (min_weight == numeric_limits<long long>::max() ? -1 : min_weight);
  }

 private:
  void dijkstra(int src, vector<vector<pair<int, int>>>& graph,
                vector<long long>& distance) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;
    distance[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
      auto [curr_distance, curr] = pq.top();
      pq.pop();
      if (distance[curr] < curr_distance) {
        continue;
      }
      for (const auto [adj_weight, adj] : graph[curr]) {
        if (distance[adj] > distance[curr] + adj_weight) {
          distance[adj] = distance[curr] + adj_weight;
          pq.push({distance[adj], adj});
        }
      }
    }
  }
};
