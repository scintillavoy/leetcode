#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  long long splitArray(vector<int>& nums) {
    int n = nums.size();
    vector<bool> sieve(n, true);
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i <= sqrt(n); ++i) {
      if (!sieve[i]) {
        continue;
      }
      for (int j = i * i; j <= n; j += i) {
        sieve[j] = false;
      }
    }
    long long diff = 0;
    for (int i = 0; i < n; ++i) {
      if (sieve[i]) {
        diff += nums[i];
      } else {
        diff -= nums[i];
      }
    }
    return abs(diff);
  }
};
