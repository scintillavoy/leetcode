#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  bool primeSubOperation(vector<int>& nums) {
    int max_num = *max_element(nums.begin(), nums.end());
    vector<bool> sieve(max_num + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i <= sqrt(max_num); ++i) {
      if (!sieve[i]) {
        continue;
      }
      for (int j = i * i; j <= max_num; j += i) {
        sieve[j] = false;
      }
    }
    vector<int> primes;
    for (int i = 0; i < sieve.size(); ++i) {
      if (sieve[i]) {
        primes.push_back(i);
      }
    }
    int prev_num = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (prev_num >= nums[i]) {
        return false;
      }
      auto it = lower_bound(primes.begin(), primes.end(), nums[i] - prev_num);
      if (it != primes.begin()) {
        nums[i] -= *(it - 1);
      }
      prev_num = nums[i];
    }
    return true;
  }
};
