#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    parents = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      parents[i] = i;
    }
    ranks = vector<int>(n);
    int result = n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (isConnected[i][j] == 1 && union_set(i, j)) {
          --result;
        }
      }
    }
    return result;
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
