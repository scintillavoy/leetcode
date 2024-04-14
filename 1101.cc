#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int earliestAcq(vector<vector<int>>& logs, int n) {
    parent = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
    ranks = vector<int>(n);
    count = n;
    sort(logs.begin(), logs.end());
    for (const auto& log : logs) {
      union_set(log[1], log[2]);
      if (count == 1) {
        return log[0];
      }
    }
    return -1;
  }

 private:
  vector<int> parent;
  vector<int> ranks;
  int count;

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
    --count;
    if (ranks[x] > ranks[y]) {
      swap(x, y);
    } else if (ranks[x] == ranks[y]) {
      ++ranks[y];
    }
    parent[x] = y;
  }
};
