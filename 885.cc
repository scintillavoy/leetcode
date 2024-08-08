#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                      int cStart) {
    vector<vector<int>> result;
    int x = rStart, y = cStart;
    int direction = 0;
    int remaining_steps = 1;
    int max_steps = 1;
    while (result.size() < rows * cols) {
      if (0 <= x && x < rows && 0 <= y && y < cols) {
        result.push_back({x, y});
      }
      x += dx[direction];
      y += dy[direction];
      --remaining_steps;
      if (remaining_steps == 0) {
        direction = (direction + 1) % 4;
        if (direction == 0 || direction == 2) {
          ++max_steps;
        }
        remaining_steps = max_steps;
      }
    }
    return result;
  }

 private:
  const int dx[4] = {0, 1, 0, -1};
  const int dy[4] = {1, 0, -1, 0};
};
