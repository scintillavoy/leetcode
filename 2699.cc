#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges,
                                         int source, int destination,
                                         int target) {
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < edges.size(); ++i) {
      graph[edges[i][0]].push_back({edges[i][1], i});
      graph[edges[i][1]].push_back({edges[i][0], i});
    }
    vector<vector<int>> distances(n,
                                  vector<int>(2, numeric_limits<int>::max()));
    dijkstra(graph, edges, source, destination, distances, 0, 0);
    if (target < distances[destination][0]) {
      return {};
    }
    dijkstra(graph, edges, source, destination, distances, 1,
             target - distances[destination][0]);
    if (distances[destination][1] < target) {
      return {};
    }
    for (auto &edge : edges) {
      if (edge[2] == -1) {
        edge[2] = 1;
      }
    }
    return edges;
  }

 private:
  void dijkstra(const vector<vector<pair<int, int>>> &graph,
                vector<vector<int>> &edges, int source, int destination,
                vector<vector<int>> &distances, int order, int difference) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    distances[source][order] = 0;
    pq.push({0, source});
    while (!pq.empty()) {
      auto [curr_distance, curr] = pq.top();
      pq.pop();
      if (distances[curr][order] < curr_distance) {
        continue;
      }
      for (const auto [adj, edge_index] : graph[curr]) {
        int weight = edges[edge_index][2];
        if (weight == -1) {
          weight = 1;
        }
        if (order == 1 && edges[edge_index][2] == -1) {
          int new_weight = difference + distances[adj][0] - distances[curr][1];
          if (new_weight > weight) {
            weight = new_weight;
            edges[edge_index][2] = new_weight;
          }
        }
        if (distances[adj][order] > distances[curr][order] + weight) {
          distances[adj][order] = distances[curr][order] + weight;
          pq.push({distances[adj][order], adj});
        }
      }
    }
  }
};
