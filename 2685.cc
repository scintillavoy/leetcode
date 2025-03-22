#include <vector>
using namespace std;

class Solution {
 public:
  int countCompleteComponents(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    for (const auto &edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    int answer = 0;
    vector<bool> visited(n);
    for (int i = 0; i < n; ++i) {
      if (visited[i]) {
        continue;
      }
      vector<int> components;
      visited[i] = true;
      components.push_back(i);
      for (int i = 0; i < components.size(); ++i) {
        int curr = components[i];
        for (const auto &adj : graph[curr]) {
          if (visited[adj]) {
            continue;
          }
          visited[adj] = true;
          components.push_back(adj);
        }
      }
      int num_of_edges = 0;
      for (const auto &component : components) {
        num_of_edges += graph[component].size();
      }
      if (num_of_edges == components.size() * (components.size() - 1)) {
        ++answer;
      }
    }
    return answer;
  }
};
