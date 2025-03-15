#include <algorithm>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  string addBoldTag(string s, vector<string>& words) {
    vector<pair<int, int>> intervals;
    for (const auto& word : words) {
      for (string::size_type index = s.find(word, 0); index != string::npos;
           index = s.find(word, index + 1)) {
        intervals.push_back({index, index + word.size()});
      }
    }
    sort(intervals.begin(), intervals.end());
    string result;
    int s_index = 0;
    for (int i = 0; i < intervals.size(); ++i) {
      while (s_index < intervals[i].first) {
        result += s[s_index];
        ++s_index;
      }
      while (i + 1 < intervals.size() &&
             intervals[i].second >= intervals[i + 1].first) {
        intervals[i + 1] = {intervals[i].first,
                            max(intervals[i].second, intervals[i + 1].second)};
        ++i;
      }
      result += "<b>";
      while (s_index < intervals[i].second) {
        result += s[s_index];
        ++s_index;
      }
      result += "</b>";
    }
    while (s_index < s.size()) {
      result += s[s_index];
      ++s_index;
    }
    return result;
  }
};
