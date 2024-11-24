#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  long long maxMatrixSum(vector<vector<int>>& matrix) {
    int num_of_negatives = 0;
    int min_abs = numeric_limits<int>::max();
    long long sum = 0;
    for (const auto& row : matrix) {
      for (auto value : row) {
        if (value < 0) {
          ++num_of_negatives;
          value *= -1;
        }
        min_abs = min(min_abs, value);
        sum += value;
      }
    }
    if (num_of_negatives % 2 == 1) {
      sum -= min_abs * 2;
    }
    return sum;
  }
};
