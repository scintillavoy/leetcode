#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  int longestSubstring(string s, int k) {
    unordered_set<char> character_set;
    for (const auto ch : s) {
      character_set.insert(ch);
    }
    int max_length = 0;
    for (int i = 1; i <= character_set.size(); ++i) {
      unordered_map<char, int> counts;
      int low = 0;
      int high = 0;
      while (high < s.size()) {
        if (counts.size() <= i) {
          ++counts[s[high]];
          ++high;
        } else {
          --counts[s[low]];
          if (counts[s[low]] == 0) {
            counts.erase(s[low]);
          }
          ++low;
        }
        if (counts.size() == i) {
          int num_of_counts_at_least_k = 0;
          for (const auto [_, count] : counts) {
            if (count >= k) {
              ++num_of_counts_at_least_k;
            }
          }
          if (num_of_counts_at_least_k == counts.size()) {
            max_length = max(max_length, high - low);
          }
        }
      }
    }
    return max_length;
  }
};
