#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    for (int i = 0; i < equations.size(); ++i) {
      graph[equations[i][0]].push_back({equations[i][1], values[i]});
      graph[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
    }
    vector<double> result;
    for (const auto& query : queries) {
      if (graph.count(query[0]) == 0 || graph.count(query[1]) == 0) {
        result.push_back(-1.0);
      } else {
        result.push_back(dfs(query[0], query[1], 1));
        visited.clear();
      }
    }
    return result;
  }

 private:
  unordered_map<string, vector<pair<string, double>>> graph;
  unordered_set<string> visited;

  double dfs(const string& curr, const string& dest, double curr_distance) {
    if (curr == dest) {
      return curr_distance;
    }
    visited.insert(curr);
    for (const auto& [adj, weight] : graph[curr]) {
      if (visited.count(adj) > 0) {
        continue;
      }
      double dist = dfs(adj, dest, curr_distance * weight);
      if (dist != -1) {
        return dist;
      }
    }
    return -1;
  }
};
