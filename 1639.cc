#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define MOD 1'000'000'007

class Solution {
 public:
  int numWays(vector<string>& words, string target) {
    vector<unordered_map<char, int>> char_counts(words[0].size());
    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j < words[0].size(); ++j) {
        ++char_counts[j][words[i][j]];
      }
    }
    vector<int> dp(char_counts.size() + 1, 1);
    for (int i = 0; i < target.size(); ++i) {
      vector<int> next_dp(char_counts.size() + 1);
      for (int j = i + 1; j <= char_counts.size(); ++j) {
        next_dp[j] =
            (next_dp[j - 1] +
             (long long)dp[j - 1] * char_counts[j - 1][target[i]] % MOD) %
            MOD;
      }
      dp = next_dp;
    }
    return dp.back();
  }
};
