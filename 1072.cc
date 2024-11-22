#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    unordered_map<string, int> frequencies;
    for (int i = 0; i < matrix.size(); ++i) {
      string pattern;
      for (int j = 0; j < matrix[0].size(); ++j) {
        pattern.push_back(matrix[i][j] == matrix[i][0] ? 'T' : 'F');
      }
      ++frequencies[pattern];
    }
    int max_frequency = 0;
    for (const auto& [_, frequency] : frequencies) {
      max_frequency = max(max_frequency, frequency);
    }
    return max_frequency;
  }
};
