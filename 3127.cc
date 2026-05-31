#include <vector>
using namespace std;

class Solution {
 public:
  bool canMakeSquare(vector<vector<char>>& grid) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        int num_of_blacks = 0;
        for (int k = 0; k < 4; ++k) {
          if (grid[i + dx[k]][j + dy[k]] == 'B') {
            ++num_of_blacks;
          }
        }
        if (num_of_blacks != 2) {
          return true;
        }
      }
    }
    return false;
  }

 private:
  const int dx[4] = {0, 1, 0, 1};
  const int dy[4] = {0, 0, 1, 1};
};
