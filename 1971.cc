#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  bool validPath(int n, vector<vector<int>>& edges, int source,
                 int destination) {
    parent = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
    rank = vector<int>(n);
    for (const auto& edge : edges) {
      union_set(edge[0], edge[1]);
    }
    return find_set(source) == find_set(destination);
  }

 private:
  vector<int> parent;
  vector<int> rank;

  int find_set(int x) {
    if (parent[x] != x) {
      parent[x] = find_set(parent[x]);
    }
    return parent[x];
  }

  void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) {
      return;
    }
    if (rank[x] > rank[y]) {
      swap(x, y);
    } else if (rank[x] == rank[y]) {
      ++rank[y];
    }
    parent[x] = y;
  }
};
