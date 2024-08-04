#include <string>
#include <vector>
using namespace std;

#define MOD 1'000'000'007

class Solution {
 public:
  int distinctSubseqII(string s) {
    vector<int> duplicates(26, -1);
    int result = 0;
    for (const auto c : s) {
      int prev_result = result;
      if (duplicates[c - 'a'] == -1) {
        result = result * 2 + 1;
      } else {
        result = result * 2 - duplicates[c - 'a'];
      }
      if (result < 0) {
        result += MOD;
      }
      result %= MOD;
      duplicates[c - 'a'] = prev_result;
    }
    return result;
  }
};
