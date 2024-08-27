#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  double maxProbability(int n, vector<vector<int>>& edges,
                        vector<double>& succProb, int start_node,
                        int end_node) {
    vector<vector<pair<double, int>>> graph(n);
    for (int i = 0; i < edges.size(); ++i) {
      graph[edges[i][0]].push_back({succProb[i], edges[i][1]});
      graph[edges[i][1]].push_back({succProb[i], edges[i][0]});
    }
    vector<double> probabilities(n);
    priority_queue<pair<double, int>> pq;
    probabilities[start_node] = 1.0;
    pq.push({1.0, start_node});
    while (!pq.empty()) {
      auto [curr_probability, curr] = pq.top();
      pq.pop();
      if (probabilities[curr] < curr_probability) {
        continue;
      }
      for (const auto [adj_probability, adj] : graph[curr]) {
        if (probabilities[adj] < curr_probability * adj_probability) {
          probabilities[adj] = curr_probability * adj_probability;
          pq.push({probabilities[adj], adj});
        }
      }
    }
    return probabilities[end_node];
  }
};
