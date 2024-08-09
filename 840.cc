#include <vector>
using namespace std;

class Solution {
 public:
  int numMagicSquaresInside(vector<vector<int>>& grid) {
    int result = 0;
    for (int i = 2; i < grid.size(); ++i) {
      for (int j = 2; j < grid[0].size(); ++j) {
        if (is_magic_square(grid, i - 2, j - 2)) {
          ++result;
        }
      }
    }
    return result;
  }

 private:
  bool is_magic_square(const vector<vector<int>>& grid, int x, int y) {
    vector<bool> exist(10);
    vector<int> row_sum(3), col_sum(3), diagonal_sum(2);
    for (int i = 0; i <= 2; ++i) {
      for (int j = 0; j <= 2; ++j) {
        if (grid[x + i][y + j] <= 0 || grid[x + i][y + j] >= 10 ||
            exist[grid[x + i][y + j]]) {
          return false;
        }
        exist[grid[x + i][y + j]] = true;
        row_sum[i] += grid[x + i][y + j];
        col_sum[j] += grid[x + i][y + j];
        if (i == j) {
          diagonal_sum[0] += grid[x + i][y + j];
        }
        if (i + j == 2) {
          diagonal_sum[1] += grid[x + i][y + j];
        }
      }
    }
    for (const auto sum : row_sum) {
      if (sum != 15) {
        return false;
      }
    }
    for (const auto sum : col_sum) {
      if (sum != 15) {
        return false;
      }
    }
    for (const auto sum : diagonal_sum) {
      if (sum != 15) {
        return false;
      }
    }
    return true;
  }
};
