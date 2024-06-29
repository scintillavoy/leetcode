#include <algorithm>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);
    vector<int> in_degree(n);
    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      ++in_degree[edge[1]];
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (in_degree[i] == 0) {
        q.push(i);
      }
    }

    vector<unordered_set<int>> ancestor_sets(n);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (const auto adj : graph[curr]) {
        for (const auto ancestor : ancestor_sets[curr]) {
          ancestor_sets[adj].insert(ancestor);
        }
        ancestor_sets[adj].insert(curr);
        --in_degree[adj];
        if (in_degree[adj] == 0) {
          q.push(adj);
        }
      }
    }

    vector<vector<int>> ancestors;
    for (int i = 0; i < n; ++i) {
      ancestors.emplace_back(ancestor_sets[i].cbegin(),
                             ancestor_sets[i].cend());
      sort(ancestors[i].begin(), ancestors[i].end());
    }

    return ancestors;
  }
};
