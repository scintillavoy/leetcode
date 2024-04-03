#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool exist(vector<vector<char>> &board, string word) {
    m = board.size();
    n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dfs(board, word, i, j, 0)) {
          return true;
        }
      }
    }
    return false;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};

  int m;
  int n;

  bool dfs(vector<vector<char>> &board, string &word, int x, int y, int depth) {
    if (depth == word.size()) {
      return true;
    }
    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[depth]) {
      return false;
    }
    char temp = board[x][y];
    board[x][y] = '#';
    bool result = false;
    for (int i = 0; i < 4; ++i) {
      if (dfs(board, word, x + dx[i], y + dy[i], depth + 1)) {
        result = true;
        break;
      }
    }
    board[x][y] = temp;
    return result;
  }
};
