#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                       vector<vector<int>>& blueEdges) {
    vector<vector<vector<int>>> graph(2, vector<vector<int>>(n));
    for (const auto& edge : redEdges) {
      graph[0][edge[0]].push_back(edge[1]);
    }
    for (const auto& edge : blueEdges) {
      graph[1][edge[0]].push_back(edge[1]);
    }
    vector<int> distances(n, -1);
    distances[0] = 0;
    traverse(n, distances, 0, graph);  // Blue first
    traverse(n, distances, 1, graph);  // Red first
    return distances;
  }

 private:
  void traverse(int n, vector<int>& distances, int color,
                const vector<vector<vector<int>>>& graph) {
    vector<vector<bool>> visited(2, vector<bool>(n));
    queue<int> q;
    visited[color][0] = true;
    q.push(0);
    int distance = 0;
    while (!q.empty()) {
      int size = q.size();
      color ^= 1;
      ++distance;
      for (int i = 0; i < size; ++i) {
        int curr = q.front();
        q.pop();
        for (const auto adj : graph[color][curr]) {
          if (visited[color][adj]) {
            continue;
          }
          if (distances[adj] == -1 || distances[adj] > distance) {
            distances[adj] = distance;
          }
          visited[color][adj] = true;
          q.push(adj);
        }
      }
    }
  }
};
