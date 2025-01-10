#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<int> max_counts(26);
    for (const auto& word : words2) {
      vector<int> counts(max_counts.size());
      for (const auto c : word) {
        ++counts[c - 'a'];
      }
      for (int i = 0; i < max_counts.size(); ++i) {
        max_counts[i] = max(max_counts[i], counts[i]);
      }
    }
    vector<string> result;
    for (const auto& word : words1) {
      vector<int> counts(max_counts.size());
      for (const auto c : word) {
        ++counts[c - 'a'];
      }
      bool is_universal = true;
      for (int i = 0; i < max_counts.size(); ++i) {
        if (counts[i] < max_counts[i]) {
          is_universal = false;
          break;
        }
      }
      if (is_universal) {
        result.push_back(word);
      }
    }
    return result;
  }
};
