#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
    int n = s.size();
    vector<vector<int>> cumulative_counts(n + 1, vector<int>(26));
    for (int i = 0; i < s.size(); ++i) {
      cumulative_counts[i + 1] = cumulative_counts[i];
      ++cumulative_counts[i + 1][s[i] - 'a'];
    }
    vector<int> result;
    for (const auto& query : queries) {
      int left = query[0], right = query[1];
      int substring_count = 0;
      for (int i = 0; i < 26; ++i) {
        int count =
            cumulative_counts[right + 1][i] - cumulative_counts[left][i];
        substring_count += count * (count + 1) / 2;
      }
      result.push_back(substring_count);
    }
    return result;
  }
};
