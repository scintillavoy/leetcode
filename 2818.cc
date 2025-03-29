#include <algorithm>
#include <cmath>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

#define MOD 1'000'000'007

class Solution {
 public:
  int maximumScore(vector<int>& nums, int k) {
    vector<int> primes = find_primes(*max_element(nums.cbegin(), nums.cend()));
    vector<pair<int, long long>> num_of_operations(
        nums.size());           // (num, num_of_operations) pairs
    stack<pair<int, int>> stk;  // (index, prime_score) pairs
    for (int i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      int prime_score = 0;
      for (const auto prime : primes) {
        if (prime * prime > num) {
          break;
        }
        if (num % prime != 0) {
          continue;
        }
        ++prime_score;
        while (num % prime == 0) {
          num /= prime;
        }
      }
      if (num > 1) {
        ++prime_score;
      }
      while (!stk.empty() && stk.top().second < prime_score) {
        auto t = stk.top();
        stk.pop();
        int left = t.first - (stk.empty() ? -1 : stk.top().first);
        int right = i - t.first;
        num_of_operations[t.first] = {nums[t.first], (long long)left * right};
      }
      stk.push({i, prime_score});
    }
    while (!stk.empty()) {
      auto t = stk.top();
      stk.pop();
      int left = t.first - (stk.empty() ? -1 : stk.top().first);
      int right = nums.size() - t.first;
      num_of_operations[t.first] = {nums[t.first], (long long)left * right};
    }
    sort(num_of_operations.rbegin(), num_of_operations.rend());
    long long max_score = 1;
    for (int i = 0; i < num_of_operations.size() && k > 0; ++i) {
      max_score =
          (max_score * power(num_of_operations[i].first,
                             min(num_of_operations[i].second, (long long)k))) %
          MOD;
      k -= num_of_operations[i].second;
    }
    return max_score;
  }

 private:
  vector<int> find_primes(int max_num) {
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
    for (int i = 2; i < sieve.size(); ++i) {
      if (sieve[i]) {
        primes.push_back(i);
      }
    }
    return primes;
  }

  long long power(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
      if (exponent % 2 == 1) {
        result = (result * base) % MOD;
      }
      base = (base * base) % MOD;
      exponent /= 2;
    }
    return result;
  }
};
