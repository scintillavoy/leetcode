#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) {
      return false;
    }
    vector<bool> dp(s2.size() + 1);
    dp[0] = true;
    for (int i = 0; i < s3.size(); ++i) {
      for (int j = dp.size() - 1; j >= 0; --j) {
        if (!dp[j]) {
          continue;
        }
        if (j < s2.size() && s2[j] == s3[i] && j + 1 < dp.size() &&
            !dp[j + 1]) {
          dp[j + 1] = true;
        }
        if (i - j >= 0 && s1[i - j] == s3[i]) {
          dp[j] = true;
        } else {
          dp[j] = false;
        }
      }
    }
    for (int i = 0; i < dp.size(); ++i) {
      if (dp[i]) {
        return true;
      }
    }
    return false;
  }
};
