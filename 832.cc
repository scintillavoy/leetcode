#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    int n = image.size();
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        result[i][j] = image[i][n - 1 - j] ^ 1;
      }
    }
    return result;
  }
};
