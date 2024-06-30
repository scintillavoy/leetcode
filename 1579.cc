#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    vector<vector<vector<int>>> edges_by_type(4);
    for (const auto& edge : edges) {
      edges_by_type[edge[0]].push_back({edge[1], edge[2]});
    }
    parents = vector<int>(n + 1);
    for (int i = 0; i < parents.size(); ++i) {
      parents[i] = i;
    }
    ranks = vector<int>(n + 1);

    // Both Alice and Bob
    int num_of_unions = 0;  // The graph is fully traversable if >= n-1.
    int num_of_edges = 0;   // The return value is edges.size() - num_of_edges.

    for (const auto& edge : edges_by_type[3]) {
      if (union_set(edge[0], edge[1])) {
        ++num_of_unions;
        ++num_of_edges;
        if (num_of_unions >= n - 1) {
          return edges.size() - num_of_edges;
        }
      }
    }

    // Alice
    int num_of_unions_both = num_of_unions;
    vector<int> parents_both = parents;
    vector<int> ranks_both = ranks;

    for (const auto& edge : edges_by_type[1]) {
      if (union_set(edge[0], edge[1])) {
        ++num_of_unions;
        ++num_of_edges;
        if (num_of_unions >= n - 1) {
          break;
        }
      }
    }
    if (num_of_unions < n - 1) {
      return -1;
    }

    // Bob
    num_of_unions = num_of_unions_both;
    parents = parents_both;
    ranks = ranks_both;

    for (const auto& edge : edges_by_type[2]) {
      if (union_set(edge[0], edge[1])) {
        ++num_of_unions;
        ++num_of_edges;
        if (num_of_unions >= n - 1) {
          break;
        }
      }
    }
    if (num_of_unions < n - 1) {
      return -1;
    }

    return edges.size() - num_of_edges;
  }

 private:
  vector<int> parents;
  vector<int> ranks;

  int find_set(int x) {
    if (parents[x] != x) {
      parents[x] = find_set(parents[x]);
    }
    return parents[x];
  }

  bool union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) {
      return false;
    }
    if (ranks[x] > ranks[y]) {
      swap(x, y);
    } else if (ranks[x] == ranks[y]) {
      ++ranks[y];
    }
    parents[x] = y;
    return true;
  }
};
