#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    parent =
        vector<vector<pair<int, int>>>(m, vector<pair<int, int>>(n, {-1, -1}));
    rank = vector<vector<int>>(m, vector<int>(n));
    vector<int> answer;
    int count = 0;
    for (const auto& position : positions) {
      int x = position[0], y = position[1];
      if (parent[x][y] != make_pair(-1, -1)) {
        answer.push_back(count);
        continue;
      }
      parent[x][y] = {x, y};
      ++count;
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n ||
            parent[x2][y2] == make_pair(-1, -1)) {
          continue;
        }
        if (union_set({x, y}, {x2, y2})) {
          --count;
        }
      }
      answer.push_back(count);
    }
    return answer;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};

  vector<vector<pair<int, int>>> parent;
  vector<vector<int>> rank;

  pair<int, int> find_set(pair<int, int> x) {
    if (parent[x.first][x.second] != x) {
      parent[x.first][x.second] = find_set(parent[x.first][x.second]);
    }
    return parent[x.first][x.second];
  }

  bool union_set(pair<int, int> x, pair<int, int> y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) {
      return false;
    }
    if (rank[x.first][x.second] > rank[y.first][y.second]) {
      swap(x, y);
    } else if (rank[x.first][x.second] == rank[y.first][y.second]) {
      ++rank[y.first][y.second];
    }
    parent[x.first][x.second] = y;
    return true;
  }
};
