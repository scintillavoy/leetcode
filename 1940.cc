#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
    vector<int> result = arrays[0];
    for (int i = 1; i < arrays.size(); ++i) {
      vector<int> next;
      int j = 0, k = 0;
      while (j < result.size() && k < arrays[i].size()) {
        if (result[j] == arrays[i][k]) {
          next.push_back(result[j]);
          ++j;
          ++k;
        } else if (result[j] < arrays[i][k]) {
          ++j;
        } else {
          ++k;
        }
      }
      result = next;
    }
    return result;
  }
};
