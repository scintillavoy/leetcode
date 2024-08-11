#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int minDays(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    if (get_num_of_islands(grid) != 1) {
      return 0;
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          continue;
        }
        grid[i][j] = 0;
        int num_of_islands = get_num_of_islands(grid);
        grid[i][j] = 1;
        if (num_of_islands != 1) {
          return 1;
        }
      }
    }
    return 2;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};

  int m;
  int n;
  vector<vector<pair<int, int>>> parents;
  vector<vector<int>> ranks;

  pair<int, int> find_set(pair<int, int> x) {
    if (parents[x.first][x.second] != x) {
      parents[x.first][x.second] = find_set(parents[x.first][x.second]);
    }
    return parents[x.first][x.second];
  }

  bool union_set(pair<int, int> x, pair<int, int> y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) {
      return false;
    }
    if (ranks[x.first][x.second] > ranks[y.first][y.second]) {
      swap(x, y);
    } else if (ranks[x.first][x.second] == ranks[y.first][y.second]) {
      ++ranks[y.first][y.second];
    }
    parents[x.first][x.second] = y;
    return true;
  }

  int get_num_of_islands(const vector<vector<int>>& grid) {
    parents = vector<vector<pair<int, int>>>(m, vector<pair<int, int>>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        parents[i][j] = {i, j};
      }
    }
    ranks = vector<vector<int>>(m, vector<int>(n));
    int num_of_islands = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          continue;
        }
        ++num_of_islands;
        for (int k = 0; k < 4; ++k) {
          int x2 = i + dx[k];
          int y2 = j + dy[k];
          if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || grid[x2][y2] == 0) {
            continue;
          }
          if (union_set({i, j}, {x2, y2})) {
            --num_of_islands;
          }
        }
      }
    }
    return num_of_islands;
  }
};
