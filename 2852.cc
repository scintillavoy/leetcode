#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  long long sumRemoteness(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    parents = vector<vector<pair<int, int>>>(m, vector<pair<int, int>>(n));
    ranks = vector<vector<int>>(m, vector<int>(n));
    sums = vector<vector<long long>>(m, vector<long long>(n));
    long long total_sum = 0;
    long long remoteness_sum = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        parents[i][j] = {i, j};
        if (grid[i][j] == -1) {
          continue;
        }
        sums[i][j] = grid[i][j];
        total_sum += grid[i][j];
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == -1) {
          continue;
        }
        for (int k = 0; k < 4; ++k) {
          int i2 = i + dx[k];
          int j2 = j + dy[k];
          if (i2 < 0 || i2 >= m || j2 < 0 || j2 >= n || grid[i2][j2] == -1) {
            continue;
          }
          union_set({i, j}, {i2, j2});
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == -1) {
          continue;
        }
        pair<int, int> parent = find_set({i, j});
        remoteness_sum += total_sum - sums[parent.first][parent.second];
      }
    }
    return remoteness_sum;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};

  vector<vector<pair<int, int>>> parents;
  vector<vector<int>> ranks;
  vector<vector<long long>> sums;

  pair<int, int> find_set(pair<int, int> x) {
    if (parents[x.first][x.second] != x) {
      parents[x.first][x.second] = find_set(parents[x.first][x.second]);
    }
    return parents[x.first][x.second];
  }

  void union_set(pair<int, int> x, pair<int, int> y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) {
      return;
    }
    if (ranks[x.first][x.second] > ranks[y.first][y.second]) {
      swap(x, y);
    } else if (ranks[x.first][x.second] == ranks[y.first][y.second]) {
      ++ranks[y.first][y.second];
    }
    parents[x.first][x.second] = y;
    sums[y.first][y.second] += sums[x.first][x.second];
  }
};
