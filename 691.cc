#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int minStickers(vector<string>& stickers, string target) {
    vector<int> dp(1 << target.size(), -1);
    dp[0] = 0;
    for (int state = 0; state < dp.size(); ++state) {
      if (dp[state] == -1) {
        continue;
      }
      for (const auto& sticker : stickers) {
        int next_state = state;
        for (const auto ch : sticker) {
          for (int i = 0; i < target.size(); ++i) {
            if ((next_state & (1 << i)) != 0) {
              continue;
            }
            if (ch == target[i]) {
              next_state |= 1 << i;
              break;
            }
          }
        }
        if (dp[next_state] == -1 || dp[next_state] > dp[state] + 1) {
          dp[next_state] = dp[state] + 1;
        }
      }
    }
    return dp.back();
  }
};
