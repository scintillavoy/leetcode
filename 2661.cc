#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<pair<int, int>> indexes(arr.size());
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        indexes[mat[i][j] - 1] = {i, j};
      }
    }
    vector<int> num_of_painted_in_row(m);
    vector<int> num_of_painted_in_col(n);
    for (int i = 0; i < arr.size(); ++i) {
      auto [x, y] = indexes[arr[i] - 1];
      ++num_of_painted_in_row[x];
      ++num_of_painted_in_col[y];
      if (num_of_painted_in_row[x] == n || num_of_painted_in_col[y] == m) {
        return i;
      }
    }
    return -1;
  }
};
