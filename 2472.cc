#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxPalindromes(string s, int k) {
    vector<pair<int, int>> palindromes;

    // Find palindromes with an odd number of characters.
    for (int i = 0; i < s.size(); ++i) {
      int left = i;
      int right = i;
      while (0 <= left && right < s.size()) {
        if (s[left] != s[right]) {
          break;
        }
        if (right - left + 1 >= k) {
          palindromes.push_back({left, right});
          break;
        }
        --left;
        ++right;
      }
    }

    // Find palindromes with an even number of characters.
    for (int i = 1; i < s.size(); ++i) {
      int left = i - 1;
      int right = i;
      while (0 <= left && right < s.size()) {
        if (s[left] != s[right]) {
          break;
        }
        if (right - left + 1 >= k) {
          palindromes.push_back({left, right});
          break;
        }
        --left;
        ++right;
      }
    }

    // Sort by the end index.
    sort(palindromes.begin(), palindromes.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
           return a.second < b.second;
         });

    // Choose palindromes greedily.
    int count = 0;
    int last_end = -1;
    for (const auto [start, end] : palindromes) {
      if (start <= last_end) {
        continue;
      }
      ++count;
      last_end = end;
    }
    return count;
  }
};
