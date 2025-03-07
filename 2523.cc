#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> closestPrimes(int left, int right) {
    vector<bool> sieve(right + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i <= sqrt(right); ++i) {
      if (!sieve[i]) {
        continue;
      }
      for (int j = i * i; j <= right; j += i) {
        sieve[j] = false;
      }
    }
    vector<int> candidate;
    for (int i = left; i <= right; ++i) {
      if (sieve[i]) {
        candidate.push_back(i);
        if (candidate.size() == 2) {
          break;
        }
      }
    }
    if (candidate.size() != 2) {
      return {-1, -1};
    }
    vector<int> ans = candidate;
    int min_diff = candidate[1] - candidate[0];
    for (int i = candidate[1] + 1; i <= right; ++i) {
      if (!sieve[i]) {
        continue;
      }
      if (min_diff > i - candidate[1]) {
        min_diff = i - candidate[1];
        candidate = {candidate[1], i};
        ans = candidate;
      } else {
        candidate = {candidate[1], i};
      }
    }
    return ans;
  }
};
