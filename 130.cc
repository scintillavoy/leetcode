#include <vector>
using namespace std;

class Solution {
 public:
  void solve(vector<vector<char>> &board) {
    m = board.size();
    n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));
    for (int i = 1; i < m - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        if (visited[i][j] || board[i][j] != 'O') {
          continue;
        }
        if (is_surrounded(i, j, board, visited)) {
          replace(i, j, board);
        }
      }
    }
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};

  int m;
  int n;

  bool is_surrounded(int x, int y, const vector<vector<char>> &board,
                     vector<vector<bool>> &visited) {
    visited[x][y] = true;
    bool result = true;
    for (int i = 0; i < 4; ++i) {
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || visited[x2][y2] ||
          board[x2][y2] != 'O') {
        continue;
      }
      result = is_surrounded(x2, y2, board, visited) && result;
    }
    if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
      result = false;
    }
    return result;
  }

  void replace(int x, int y, vector<vector<char>> &board) {
    board[x][y] = 'X';
    for (int i = 0; i < 4; ++i) {
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || board[x2][y2] != 'O') {
        continue;
      }
      replace(x2, y2, board);
    }
  }
};
