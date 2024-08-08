#include <vector>
using namespace std;

class Solution {
 public:
  int numberOfPatterns(int m, int n) {
    center = vector<vector<int>>(10, vector<int>(10));
    center[1][3] = 2;
    center[3][1] = 2;
    center[4][6] = 5;
    center[6][4] = 5;
    center[7][9] = 8;
    center[9][7] = 8;
    center[1][7] = 4;
    center[7][1] = 4;
    center[2][8] = 5;
    center[8][2] = 5;
    center[3][9] = 6;
    center[9][3] = 6;
    center[1][9] = 5;
    center[9][1] = 5;
    center[3][7] = 5;
    center[7][3] = 5;
    counts_by_length = vector<int>(10);
    for (int i = 1; i <= 9; ++i) {
      backtrack(1, 1 << i, i);
    }
    int result = 0;
    for (int i = m; i <= n; ++i) {
      result += counts_by_length[i];
    }
    return result;
  }

 private:
  vector<vector<int>> center;
  vector<int> counts_by_length;

  void backtrack(int length, int mask, int curr) {
    ++counts_by_length[length];
    if (length == 9) {
      return;
    }
    for (int i = 1; i <= 9; ++i) {
      if ((mask & (1 << i)) != 0 ||
          (center[curr][i] != 0 && (mask & (1 << center[curr][i])) == 0)) {
        continue;
      }
      backtrack(length + 1, mask | (1 << i), i);
    }
  }
};
