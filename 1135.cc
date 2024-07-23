#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumCost(int n, vector<vector<int>> &connections) {
    parents = vector<int>(n + 1);
    for (int i = 1; i < n + 1; ++i) {
      parents[i] = i;
    }
    ranks = vector<int>(n + 1);
    int min_cost = 0;
    int num_of_unions = 0;
    sort(
        connections.begin(), connections.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[2] < b[2]; });
    for (const auto &connection : connections) {
      if (union_set(connection[0], connection[1])) {
        min_cost += connection[2];
        ++num_of_unions;
      }
    }
    if (num_of_unions < n - 1) {
      return -1;
    }
    return min_cost;
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
