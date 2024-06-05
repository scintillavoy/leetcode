#include <limits>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    vector<int> counts(26, numeric_limits<int>::max());
    for (const auto& word : words) {
      vector<int> curr_counts(26);
      for (const auto c : word) {
        ++curr_counts[c - 'a'];
      }
      for (int i = 0; i < counts.size(); ++i) {
        counts[i] = min(counts[i], curr_counts[i]);
      }
    }
    vector<string> result;
    for (int i = 0; i < counts.size(); ++i) {
      while (counts[i] > 0) {
        result.push_back(string{char(i + 'a')});
        --counts[i];
      }
    }
    return result;
  }
};
