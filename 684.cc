#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    parents = vector<int>(n + 1);
    for (int i = 1; i <= n; ++i) {
      parents[i] = i;
    }
    ranks = vector<int>(n + 1);
    for (const auto& edge : edges) {
      if (!union_set(edge[0], edge[1])) {
        return edge;
      }
    }
    return {};
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
