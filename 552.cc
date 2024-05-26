#include <vector>
using namespace std;

#define MOD 1'000'000'007

class Solution {
 public:
  int checkRecord(int n) {
    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(3, vector<int>(2)));
    dp[0][0][0] = 1;
    for (int i = 1; i < n + 1; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 2; ++k) {
          if (j == 0) {
            for (int l = 0; l < 3; ++l) {
              dp[i][j][k] = (dp[i][j][k] + dp[i - 1][l][k]) % MOD;
              if (k >= 1) {
                dp[i][j][k] = (dp[i][j][k] + dp[i - 1][l][k - 1]) % MOD;
              }
            }
          } else {
            dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k]) % MOD;
          }
        }
      }
    }

    int result = 0;
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 2; ++k) {
        result = (result + dp[n][j][k]) % MOD;
      }
    }
    return result;
  }
};

/*
dp[i][j][k]
  i total days (0..=n)
  j consecutive late days (0..=2)
  k absent days (0..=1)

dp[i][j][k] =
  P if j == 0,           + dp[i-1][0..=2][k]
  A if j == 0 && k >= 1, + dp[i-1][0..=2][k-1]
  L if j >= 1,           + dp[i-1][j-1][k]

Result: sum of dp[n][0..=2][0..=1]
Notes:
  - Apply modulo operation.

# Examples

n=1 result=3
P
L
A

n=2 result=8
PP
PL
PA
LP
LL
LA
AP
AL

n=3 result=19
PPP
PPL
PPA
PLP
PLL
PLA
PAP
PAL
LPP
LPL
LPA
LLP
LLA
LAP
LAL
APP
APL
ALP
ALL

dp[0][0][0] = 1

dp[1][0][0] = dp[0][0][0] + dp[0][1][0] + dp[0][2][0] = 1
dp[1][0][1] = dp[0][0][1] + dp[0][1][1] + dp[0][2][1] +
              dp[0][0][0] + dp[0][1][0] + dp[0][2][0] = 1
dp[1][1][0] = dp[0][0][0] = 1
dp[1][1][1] = dp[0][0][1] = 0
dp[1][2][0] = dp[0][1][0] = 0
dp[1][2][1] = dp[0][1][1] = 0

dp[2][0][0] = dp[1][0][0] + dp[1][1][0] + dp[1][2][0] = 2 PP LP
dp[2][0][1] = dp[1][0][1] + dp[1][1][1] + dp[1][2][1] +
              dp[1][0][0] + dp[1][1][0] + dp[1][2][0] = 3 PA LA AP
dp[2][1][0] = dp[1][0][0] = 1 PL
dp[2][1][1] = dp[1][0][1] = 1 AL
dp[2][2][0] = dp[1][1][0] = 1 LL
dp[2][2][1] = dp[1][1][1] = 0
*/
