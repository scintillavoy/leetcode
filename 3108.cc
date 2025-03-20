#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> minimumCost(int n, vector<vector<int>>& edges,
                          vector<vector<int>>& query) {
    parents = vector<int>(n);
    for (int i = 0; i < parents.size(); ++i) {
      parents[i] = i;
    }
    ranks = vector<int>(n);
    min_costs = vector<int>(n, ~0);
    for (const auto& edge : edges) {
      int parent = union_set(edge[0], edge[1]);
      min_costs[parent] &= edge[2];
    }
    vector<int> result;
    for (const auto& q : query) {
      int x = find_set(q[0]);
      int y = find_set(q[1]);
      if (x == y) {
        result.push_back(min_costs[x]);
      } else {
        result.push_back(-1);
      }
    }
    return result;
  }

 private:
  vector<int> parents;
  vector<int> ranks;
  vector<int> min_costs;

  int find_set(int x) {
    if (parents[x] != x) {
      parents[x] = find_set(parents[x]);
    }
    return parents[x];
  }

  int union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) {
      return x;
    }
    if (ranks[x] > ranks[y]) {
      swap(x, y);
    } else if (ranks[x] == ranks[y]) {
      ++ranks[y];
    }
    parents[x] = y;
    min_costs[y] &= min_costs[x];
    return y;
  }
};
