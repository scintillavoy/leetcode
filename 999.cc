#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int numRookCaptures(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    pair<int, int> rook_coordinate;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'R') {
          rook_coordinate = {i, j};
          break;
        }
      }
    }
    int result = 0;
    for (int i = 0; i < 4; ++i) {
      int x = rook_coordinate.first + dx[i];
      int y = rook_coordinate.second + dy[i];
      while (0 <= x && x < m && 0 <= y && y < n) {
        if (board[x][y] == 'p') {
          ++result;
          break;
        }
        if (board[x][y] == 'B') {
          break;
        }
        x += dx[i];
        y += dy[i];
      }
    }
    return result;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
