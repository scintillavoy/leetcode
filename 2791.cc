#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  long long countPalindromePaths(vector<int>& parent, string s) {
    int n = parent.size();
    vector<vector<int>> children(n);
    for (int i = 1; i < n; ++i) {
      children[parent[i]].push_back(i);
    }
    unordered_map<int, int> counts;
    counts[0] = 1;
    return traverse(0, 0, children, s, counts);
  }

 private:
  long long traverse(int curr, int mask, const vector<vector<int>>& children,
                     const string& s, unordered_map<int, int>& counts) {
    long long num_of_paths = 0;
    if (curr > 0) {
      mask ^= 1 << (s[curr] - 'a');
      for (int i = 1 << 25; i > 0; i >>= 1) {
        if (counts.contains(mask ^ i)) {
          num_of_paths += counts[mask ^ i];
        }
      }
      num_of_paths += counts[mask];
      ++counts[mask];
    }
    for (const auto child : children[curr]) {
      num_of_paths += traverse(child, mask, children, s, counts);
    }
    return num_of_paths;
  }
};
