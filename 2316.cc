#include <vector>
using namespace std;

class Solution {
 public:
  long long countPairs(int n, vector<vector<int>>& edges) {
    parents = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      parents[i] = i;
    }
    ranks = vector<int>(n);
    sizes = vector<int>(n, 1);
    for (const auto& edge : edges) {
      union_set(edge[0], edge[1]);
    }
    long long result = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      if (parents[i] == i) {
        result += (long long)sum * sizes[i];
        sum += sizes[i];
      }
    }
    return result;
  }

 private:
  vector<int> parents;
  vector<int> ranks;
  vector<int> sizes;

  int find_set(int x) {
    if (parents[x] != x) {
      parents[x] = find_set(parents[x]);
    }
    return parents[x];
  }

  void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) {
      return;
    }
    if (ranks[x] > ranks[y]) {
      swap(x, y);
    } else if (ranks[x] == ranks[y]) {
      ++ranks[y];
    }
    parents[x] = y;
    sizes[y] += sizes[x];
  }
};
