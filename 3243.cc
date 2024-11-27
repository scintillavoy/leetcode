#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> shortestDistanceAfterQueries(int n,
                                           vector<vector<int>>& queries) {
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; ++i) {
      graph[i].push_back(i + 1);
    }
    vector<int> min_distances(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      graph[queries[i][0]].push_back(queries[i][1]);
      min_distances[i] = find_min_distance(graph);
    }
    return min_distances;
  }

 private:
  int find_min_distance(const vector<vector<int>>& graph) {
    vector<bool> visited(graph.size());
    queue<int> q;
    visited[0] = true;
    q.push(0);
    int min_distance = 1;
    while (!q.empty()) {
      for (int i = q.size(); i > 0; --i) {
        int curr = q.front();
        q.pop();
        for (const auto adj : graph[curr]) {
          if (visited[adj]) {
            continue;
          }
          if (adj == graph.size() - 1) {
            return min_distance;
          }
          visited[adj] = true;
          q.push(adj);
        }
      }
      ++min_distance;
    }
    return -1;
  }
};
