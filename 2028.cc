#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int remaining = mean * (n + rolls.size());
    for (const auto roll : rolls) {
      remaining -= roll;
    }
    if (remaining < n || remaining > n * 6) {
      return {};
    }
    vector<int> result(n, remaining / n);
    remaining %= n;
    for (int i = 0; i < remaining; ++i) {
      ++result[i];
    }
    return result;
  }
};
