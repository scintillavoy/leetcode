#include <vector>
using namespace std;

class Solution {
 public:
  int maxMoves(vector<vector<int>>& grid) {
    int max_move = 0;
    vector<bool> reachable_rows(grid.size(), true);
    for (int col = 0; col < grid[0].size() - 1; ++col) {
      vector<bool> next_reachable_rows(grid.size());
      for (int row = 0; row < grid.size(); ++row) {
        if (!reachable_rows[row]) {
          continue;
        }
        for (int i = 0; i < 3; ++i) {
          int next_col = col + 1;
          int next_row = row + dr[i];
          if (next_row < 0 || next_row >= grid.size() ||
              grid[row][col] >= grid[next_row][next_col]) {
            continue;
          }
          max_move = next_col;
          next_reachable_rows[next_row] = true;
        }
      }
      reachable_rows = next_reachable_rows;
    }
    return max_move;
  }

 private:
  const int dr[3] = {-1, 0, 1};
};
