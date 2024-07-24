#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  bool validTree(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) {
      return false;
    }
    parents = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      parents[i] = i;
    }
    ranks = vector<int>(n);
    for (const auto& edge : edges) {
      if (!union_set(edge[0], edge[1])) {
        return false;
      }
    }
    return true;
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
