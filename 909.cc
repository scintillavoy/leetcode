#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<int> cells(n * n + 1);
    int cell_index = 1;
    for (int i = n - 1; i >= 0; i -= 2) {
      for (int j = 0; j < n; ++j) {
        cells[cell_index] = board[i][j];
        ++cell_index;
      }
      if (i - 1 < 0) {
        continue;
      }
      for (int j = n - 1; j >= 0; --j) {
        cells[cell_index] = board[i - 1][j];
        ++cell_index;
      }
    }
    queue<int> q;
    vector<int> visited(cells.size());
    q.push(1);
    visited[1] = true;
    int num_of_moves = 0;
    while (!q.empty()) {
      ++num_of_moves;
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        int curr = q.front();
        q.pop();
        for (int j = 1; j <= 6; ++j) {
          if (curr + j >= cells.size()) {
            continue;
          }
          int adj = cells[curr + j] == -1 ? curr + j : cells[curr + j];
          if (adj == n * n) {
            return num_of_moves;
          }
          if (visited[adj]) {
            continue;
          }
          q.push(adj);
          visited[adj] = true;
        }
      }
    }
    return -1;
  }
};
