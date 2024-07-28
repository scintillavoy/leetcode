#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    unordered_map<string, int> m;
    for (int i = 0; i < n; ++i) {
      string row;
      for (int j = 0; j < n; ++j) {
        row += to_string(grid[i][j]) + '-';
      }
      ++m[row];
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
      string column;
      for (int j = 0; j < n; ++j) {
        column += to_string(grid[j][i]) + '-';
      }
      result += m[column];
    }
    return result;
  }
};
