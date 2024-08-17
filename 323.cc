#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int countComponents(int n, vector<vector<int>>& edges) {
    parents = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      parents[i] = i;
    }
    ranks = vector<int>(n);
    int num_of_components = n;
    for (const auto& edge : edges) {
      if (union_set(edge[0], edge[1])) {
        --num_of_components;
      }
    }
    return num_of_components;
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
