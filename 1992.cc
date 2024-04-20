#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    int m = land.size();
    int n = land[0].size();
    vector<vector<int>> answer;
    for (int x = 0; x < m; ++x) {
      for (int y = 0; y < n; ++y) {
        if (land[x][y] == 0) {
          continue;
        }
        int x2 = x, y2 = y;
        while (x2 + 1 < m && land[x2 + 1][y2] == 1) {
          ++x2;
        }
        while (y2 + 1 < n && land[x2][y2 + 1] == 1) {
          ++y2;
        }
        answer.push_back({x, y, x2, y2});
        for (int i = x; i <= x2; ++i) {
          for (int j = y; j <= y2; ++j) {
            land[i][j] = 0;
          }
        }
      }
    }
    return answer;
  }
};
