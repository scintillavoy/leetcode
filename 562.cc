#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestLine(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> prev_count(n, vector<int>(4));
    int answer = 0;
    for (int i = 0; i < m; ++i) {
      vector<vector<int>> count(n, vector<int>(4));
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 0) {
          continue;
        }
        count[j][0] = (j > 0 ? prev_count[j - 1][0] + 1 : 1);
        count[j][1] = prev_count[j][1] + 1;
        count[j][2] = (j < n - 1 ? prev_count[j + 1][2] + 1 : 1);
        count[j][3] = (j > 0 ? count[j - 1][3] + 1 : 1);
        answer = max(answer, *max_element(count[j].cbegin(), count[j].cend()));
      }
      prev_count = count;
    }
    return answer;
  }
};
