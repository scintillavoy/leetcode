#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    int row_index = 0;
    int max_num_of_ones = 0;
    for (int i = 0; i < mat.size(); ++i) {
      int num_of_ones = 0;
      for (int j = 0; j < mat[i].size(); ++j) {
        if (mat[i][j] == 1) {
          ++num_of_ones;
        }
      }
      if (max_num_of_ones < num_of_ones) {
        max_num_of_ones = num_of_ones;
        row_index = i;
      }
    }
    return {row_index, max_num_of_ones};
  }
};
