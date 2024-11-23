#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> minScore(vector<vector<int>>& grid) {
    vector<Cell> cells;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        cells.push_back({grid[i][j], i, j});
      }
    }
    sort(cells.begin(), cells.end());
    vector<int> max_value_in_row(grid.size());
    vector<int> max_value_in_column(grid[0].size());
    for (const auto& [_, x, y] : cells) {
      grid[x][y] = max(max_value_in_row[x], max_value_in_column[y]) + 1;
      max_value_in_row[x] = grid[x][y];
      max_value_in_column[y] = grid[x][y];
    }
    return grid;
  }

 private:
  struct Cell {
    int value;
    int x;
    int y;

    bool operator<(const Cell& other) const { return value < other.value; }
  };
};
