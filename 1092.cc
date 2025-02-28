#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string shortestCommonSupersequence(string str1, string str2) {
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> lengths(m + 1, vector<int>(n + 1));
    for (int i = 1; i < m + 1; ++i) {
      lengths[i][0] = i;
    }
    for (int i = 1; i < n + 1; ++i) {
      lengths[0][i] = i;
    }
    for (int i = 1; i < m + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        if (str1[i - 1] == str2[j - 1]) {
          lengths[i][j] = lengths[i - 1][j - 1] + 1;
        } else {
          lengths[i][j] = min(lengths[i - 1][j], lengths[i][j - 1]) + 1;
        }
      }
    }
    string result;
    int i = m;
    int j = n;
    while (i > 0 && j > 0) {
      if (str1[i - 1] == str2[j - 1]) {
        result.push_back(str1[i - 1]);
        --i;
        --j;
      } else if (lengths[i - 1][j] < lengths[i][j - 1]) {
        result.push_back(str1[i - 1]);
        --i;
      } else {
        result.push_back(str2[j - 1]);
        --j;
      }
    }
    while (i > 0) {
      result.push_back(str1[i - 1]);
      --i;
    }
    while (j > 0) {
      result.push_back(str2[j - 1]);
      --j;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
