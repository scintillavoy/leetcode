#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> multiply(vector<vector<int>>& mat1,
                               vector<vector<int>>& mat2) {
    int m = mat1.size();
    int n = mat2[0].size();
    vector<vector<pair<int, int>>> compressed1 = compress(mat1);
    vector<vector<pair<int, int>>> compressed2 = compress(mat2);
    vector<vector<int>> multiplied(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (const auto [value1, j] : compressed1[i]) {
        for (const auto [value2, k] : compressed2[j]) {
          multiplied[i][k] += value1 * value2;
        }
      }
    }
    return multiplied;
  }

 private:
  vector<vector<pair<int, int>>> compress(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();
    vector<vector<pair<int, int>>> compressed(rows);
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        compressed[i].push_back({matrix[i][j], j});
      }
    }
    return compressed;
  }
};
