#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
    vector<vector<int>> answer = matrix;
    unordered_map<int, int> column_to_max_value;
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[0].size(); ++j) {
        if (matrix[i][j] != -1) {
          continue;
        }
        if (!column_to_max_value.contains(j)) {
          for (int k = 0; k < matrix.size(); ++k) {
            column_to_max_value[j] = max(column_to_max_value[j], matrix[k][j]);
          }
        }
        answer[i][j] = column_to_max_value[j];
      }
    }
    return answer;
  }
};
