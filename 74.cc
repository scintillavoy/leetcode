#include <vector>
using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0;
    int high = m - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (target < matrix[mid][0]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    int row = low - 1;
    if (row == -1) {
      return false;
    }
    low = 0;
    high = n - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (target == matrix[row][mid]) {
        return true;
      } else if (target < matrix[row][mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return false;
  }
};
