#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    parent = vector<int>(n);
    for (int i = 0; i < parent.size(); ++i) {
      parent[i] = i;
    }
    rank = vector<int>(n);
    unordered_map<int, int> rows, cols;
    for (int i = 0; i < stones.size(); ++i) {
      int row = stones[i][0];
      int col = stones[i][1];
      if (rows.count(row) == 0) {
        rows[row] = i;
      } else {
        union_set(rows[row], i);
      }
      if (cols.count(col) == 0) {
        cols[col] = i;
      } else {
        union_set(cols[col], i);
      }
    }
    int result = 0;
    for (int i = 0; i < parent.size(); ++i) {
      if (parent[i] != i) {
        ++result;
      }
    }
    return result;
  }

 private:
  vector<int> parent;
  vector<int> rank;

  int find_set(int x) {
    if (x != parent[x]) {
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
