#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int mostProfitablePath(vector<vector<int>>& edges, int bob,
                         vector<int>& amount) {
    int n = edges.size() + 1;
    vector<vector<int>> graph(n);
    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    vector<int> parents = find_parents(graph);
    queue<pair<int, int>> q;
    q.push({0, 0});
    int max_profit = numeric_limits<int>::min();
    while (!q.empty()) {
      for (int i = q.size(); i > 0; --i) {
        auto [alice, profit] = q.front();
        q.pop();
        if (alice == bob) {
          profit += amount[alice] / 2;
        } else {
          profit += amount[alice];
        }
        amount[alice] = 0;
        if (graph[alice].size() == 1 && graph[alice][0] == parents[alice]) {
          max_profit = max(max_profit, profit);
        } else {
          for (const auto adj : graph[alice]) {
            if (adj != parents[alice]) {
              q.push({adj, profit});
            }
          }
        }
      }
      if (bob != -1) {
        amount[bob] = 0;
        bob = parents[bob];
      }
    }
    return max_profit;
  }

 private:
  vector<int> find_parents(const vector<vector<int>>& graph) {
    vector<int> parents(graph.size(), -1);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (const auto adj : graph[curr]) {
        if (adj == parents[curr]) {
          continue;
        }
        parents[adj] = curr;
        q.push(adj);
      }
    }
    return parents;
  }
};
