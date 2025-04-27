#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int m = img.size();
    int n = img[0].size();
    vector<vector<int>> result(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int num_of_surrounding_cells = 0;
        for (int k = i - 1; k <= i + 1; ++k) {
          for (int l = j - 1; l <= j + 1; ++l) {
            if (k >= 0 && k < m && l >= 0 && l < n) {
              result[i][j] += img[k][l];
              ++num_of_surrounding_cells;
            }
          }
        }
        result[i][j] /= num_of_surrounding_cells;
      }
    }
    return result;
  }
};
