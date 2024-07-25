#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> result(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 0) {
          result[i][j] = 0;
          q.push({i, j});
        }
      }
    }
    int d = 1;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        auto [x, y] = q.front();
        q.pop();
        for (int j = 0; j < 4; ++j) {
          int x2 = x + dx[j];
          int y2 = y + dy[j];
          if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || result[x2][y2] != -1) {
            continue;
          }
          result[x2][y2] = d;
          q.push({x2, y2});
        }
      }
      ++d;
    }
    return result;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
