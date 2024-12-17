#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int characterReplacement(string s, int k) {
    unordered_map<char, int> counts;
    int left = 0;
    int max_length = 0;
    int max_count = 0;
    for (int right = 0; right < s.size(); ++right) {
      ++counts[s[right]];
      max_count = max(max_count, counts[s[right]]);
      if (right - left + 1 - max_count <= k) {
        max_length = max(max_length, right - left + 1);
      } else {
        --counts[s[left]];
        ++left;
      }
    }
    return max_length;
  }
};
