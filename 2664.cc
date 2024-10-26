#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
    vector<vector<int>> board(m, vector<int>(n, -1));
    traverse(board, r, c, 0);
    return board;
  }

 private:
  const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
  const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

  bool traverse(vector<vector<int>> &board, int r, int c, int order) {
    board[r][c] = order;
    if (order + 1 == board.size() * board[0].size()) {
      return true;
    }
    for (int i = 0; i < 8; ++i) {
      int r2 = r + dx[i];
      int c2 = c + dy[i];
      if (r2 < 0 || r2 >= board.size() || c2 < 0 || c2 >= board[0].size() ||
          board[r2][c2] != -1) {
        continue;
      }
      if (traverse(board, r + dx[i], c + dy[i], order + 1)) {
        return true;
      }
    }
    board[r][c] = -1;
    return false;
  }
};
