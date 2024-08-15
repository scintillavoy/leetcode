#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  int minMoves(vector<vector<int>> &rooks) {
    int result = 0;
    sort(rooks.begin(), rooks.end());
    for (int i = 0; i < rooks.size(); ++i) {
      result += abs(rooks[i][0] - i);
    }
    sort(
        rooks.begin(), rooks.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });
    for (int i = 0; i < rooks.size(); ++i) {
      result += abs(rooks[i][1] - i);
    }
    return result;
  }
};
