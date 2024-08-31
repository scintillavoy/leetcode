#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define MOD 1'000'000'007

class Solution {
 public:
  int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> graph(n);
    for (const auto& road : roads) {
      graph[road[0]].push_back({road[2], road[1]});
      graph[road[1]].push_back({road[2], road[0]});
    }
    vector<long long> distances(n, numeric_limits<long long>::max());
    vector<int> ways(n);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;
    distances[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});
    while (!pq.empty()) {
      auto [curr_distance, curr] = pq.top();
      pq.pop();
      if (distances[curr] < curr_distance) {
        continue;
      }
      for (const auto [adj_weight, adj] : graph[curr]) {
        if (distances[adj] > distances[curr] + adj_weight) {
          distances[adj] = distances[curr] + adj_weight;
          ways[adj] = ways[curr];
          pq.push({distances[adj], adj});
        } else if (distances[adj] == distances[curr] + adj_weight) {
          ways[adj] = (ways[adj] + ways[curr]) % MOD;
        }
      }
    }
    return ways[n - 1];
  }
};
