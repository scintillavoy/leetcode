#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> answer(n - 2, vector<int>(n - 2));
    for (int i = 0; i < n - 2; ++i) {
      for (int j = 0; j < n - 2; ++j) {
        for (int k = i; k <= i + 2; ++k) {
          for (int l = j; l <= j + 2; ++l) {
            answer[i][j] = max(answer[i][j], grid[k][l]);
          }
        }
      }
    }
    return answer;
  }
};
