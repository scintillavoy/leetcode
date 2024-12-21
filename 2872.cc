#include <vector>
using namespace std;

class Solution {
 public:
  int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                              vector<int>& values, int k) {
    vector<vector<int>> graph(n);
    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    vector<long long> value_sums(n);
    find_value_sum(0, -1, graph, values, value_sums);
    int num_of_components = 1;
    for (int i = 1; i < value_sums.size(); ++i) {
      if (value_sums[i] % k == 0) {
        ++num_of_components;
      }
    }
    return num_of_components;
  }

 private:
  long long find_value_sum(int curr, int parent,
                           const vector<vector<int>>& graph,
                           const vector<int>& values,
                           vector<long long>& value_sums) {
    value_sums[curr] = values[curr];
    for (const auto adj : graph[curr]) {
      if (adj == parent) {
        continue;
      }
      value_sums[curr] += find_value_sum(adj, curr, graph, values, value_sums);
    }
    return value_sums[curr];
  }
};
