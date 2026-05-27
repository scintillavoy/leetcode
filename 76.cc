#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> counts;
    for (const auto ch : t) {
      ++counts[ch];
    }
    int min_length = s.size() + 1;
    int start_index = -1;
    int num_of_zero_counts = 0;
    int low = 0;
    for (int high = 0; high < s.size(); ++high) {
      if (!counts.contains(s[high])) {
        continue;
      }
      --counts[s[high]];
      if (counts[s[high]] != 0) {
        continue;
      }
      ++num_of_zero_counts;
      while (num_of_zero_counts == counts.size()) {
        if (min_length > high - low + 1) {
          min_length = high - low + 1;
          start_index = low;
        }
        if (counts.contains(s[low])) {
          if (counts[s[low]] == 0) {
            --num_of_zero_counts;
          }
          ++counts[s[low]];
        }
        ++low;
      }
    }
    if (start_index == -1) {
      return "";
    }
    return s.substr(start_index, min_length);
  }
};
