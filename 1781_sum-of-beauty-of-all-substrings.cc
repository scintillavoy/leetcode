#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int beautySum(string s) {
    if (s.size() < 3) return 0;
    int sum = 0;
    for (int len = 3; len <= s.size(); ++len) {
      unordered_map<char, int> count;
      for (int i = 0; i < len; ++i) {
        ++count[s[i]];
      }
      int max_val = 0;
      int min_val = numeric_limits<int>::max();
      for (const auto &x : count) {
        if (x.second > max_val) {
          max_val = x.second;
        }
        if (x.second < min_val) {
          min_val = x.second;
        }
      }
      sum += max_val - min_val;
      for (int i = 1; i + len - 1 < s.size(); ++i) {
        --count[s[i - 1]];
        if (count[s[i - 1]] == 0) {
          count.erase(s[i - 1]);
        }
        ++count[s[i + len - 1]];
        max_val = 0;
        min_val = numeric_limits<int>::max();
        for (const auto &x : count) {
          if (x.second > max_val) {
            max_val = x.second;
          }
          if (x.second < min_val) {
            min_val = x.second;
          }
        }
        sum += max_val - min_val;
      }
    }
    return sum;
  }
};

int main() {
  Solution sol;
  sol.beautySum("aabcc");
  return 0;
}
