#include <cmath>
#include <limits>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string nearestPalindromic(string n) {
    bool even = n.size() % 2 == 0;
    int mid_index = even ? n.size() / 2 - 1 : n.size() / 2;
    long long first_half = stoll(n.substr(0, mid_index + 1));
    vector<long long> candidates;
    candidates.push_back(half_to_palindrome(first_half, even));
    if (first_half + 1 < 1'000'000'000) {
      candidates.push_back(half_to_palindrome(first_half + 1, even));
    }
    candidates.push_back(half_to_palindrome(first_half - 1, even));
    candidates.push_back((long long)pow(10, n.size() - 1) - 1);
    candidates.push_back((long long)pow(10, n.size()) + 1);
    long long min_diff = numeric_limits<long long>::max();
    long long nearest_palindrome = -1;
    long long original_number = stoll(n);
    for (const auto candidate : candidates) {
      if (original_number == candidate) {
        continue;
      }
      long long diff = abs(original_number - candidate);
      if (min_diff > diff) {
        min_diff = diff;
        nearest_palindrome = candidate;
      } else if (min_diff == diff) {
        nearest_palindrome = min(nearest_palindrome, candidate);
      }
    }
    return to_string(nearest_palindrome);
  }

 private:
  long long half_to_palindrome(long long half, bool even) {
    long long result = half;
    if (!even) {
      half /= 10;
    }
    while (half > 0) {
      result = result * 10 + half % 10;
      half /= 10;
    }
    return result;
  }
};
