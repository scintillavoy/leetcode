#include <vector>
using namespace std;

class Solution {
 public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
      if (!check(matrix, i, 0)) {
        return false;
      }
    }
    for (int i = 0; i < matrix[0].size(); ++i) {
      if (!check(matrix, 0, i)) {
        return false;
      }
    }
    return true;
  }

 private:
  bool check(const vector<vector<int>>& matrix, int x, int y) {
    int value = matrix[x][y];
    ++x;
    ++y;
    while (0 <= x && x < matrix.size() && 0 <= y && y < matrix[0].size()) {
      if (matrix[x][y] != value) {
        return false;
      }
      ++x;
      ++y;
    }
    return true;
  }
};
