#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    m = matrix.size();
    n = matrix[0].size();
    vector<vector<int>> in_degrees(m, vector<int>(n));
    for (int x = 0; x < m; ++x) {
      for (int y = 0; y < n; ++y) {
        for (int k = 0; k < 4; ++k) {
          int x2 = x + dx[k];
          int y2 = y + dy[k];
          if (can_move(x, y, x2, y2, matrix)) {
            ++in_degrees[x2][y2];
          }
        }
      }
    }
    queue<pair<int, int>> q;
    for (int x = 0; x < m; ++x) {
      for (int y = 0; y < n; ++y) {
        if (in_degrees[x][y] == 0) {
          q.push({x, y});
        }
      }
    }
    int max_length = 0;
    while (!q.empty()) {
      ++max_length;
      for (int i = q.size(); i > 0; --i) {
        auto [x, y] = q.front();
        q.pop();
        for (int j = 0; j < 4; ++j) {
          int x2 = x + dx[j];
          int y2 = y + dy[j];
          if (can_move(x, y, x2, y2, matrix)) {
            --in_degrees[x2][y2];
            if (in_degrees[x2][y2] == 0) {
              q.push({x2, y2});
            }
          }
        }
      }
    }
    return max_length;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};

  int m;
  int n;

  bool can_move(int x1, int y1, int x2, int y2,
                const vector<vector<int>>& matrix) {
    return x2 >= 0 && x2 < m && y2 >= 0 && y2 < n &&
           matrix[x1][y1] < matrix[x2][y2];
  }
};
