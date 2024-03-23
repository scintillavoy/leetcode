#include <vector>
using namespace std;

class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> in_degree(n + 1), out_degree(n + 1);
    for (const auto& t : trust) {
      ++out_degree[t[0]];
      ++in_degree[t[1]];
    }
    vector<int> candidates;
    for (int i = 1; i <= n; ++i) {
      if (in_degree[i] == n - 1 && out_degree[i] == 0) {
        candidates.push_back(i);
      }
    }
    if (candidates.size() == 1) {
      return candidates[0];
    }
    return -1;
  }
};
