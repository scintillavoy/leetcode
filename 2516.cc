#include <algorithm>
#include <limits>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int takeCharacters(string s, int k) {
    unordered_map<char, int> removed_counts;
    for (const auto c : s) {
      ++removed_counts[c];
    }
    int min_num_of_removal = numeric_limits<int>::max();
    int left = 0;
    for (int right = 0; right < s.size(); ++right) {
      --removed_counts[s[right]];
      while (left <= right &&
             (removed_counts['a'] < k || removed_counts['b'] < k ||
              removed_counts['c'] < k)) {
        ++removed_counts[s[left]];
        ++left;
      }
      if (removed_counts['a'] >= k && removed_counts['b'] >= k &&
          removed_counts['c'] >= k) {
        min_num_of_removal =
            min(min_num_of_removal, removed_counts['a'] + removed_counts['b'] +
                                        removed_counts['c']);
      }
    }
    return min_num_of_removal == numeric_limits<int>::max()
               ? -1
               : min_num_of_removal;
  }
};
