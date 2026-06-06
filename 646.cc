#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int findLongestChain(vector<vector<int>>& pairs) {
    sort(
        pairs.begin(), pairs.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
    int last = pairs[0][0] - 1;
    int length = 0;
    for (const auto& pair : pairs) {
      if (last < pair[0]) {
        ++length;
        last = pair[1];
      }
    }
    return length;
  }
};
