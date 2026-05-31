#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    vector<int> prefix_masks(s.size() + 1);
    int prefix_mask = 0;
    for (int i = 0; i < s.size(); ++i) {
      prefix_mask ^= 1 << (s[i] - 'a');
      prefix_masks[i + 1] = prefix_mask;
    }
    vector<bool> result(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      int left = queries[i][0];
      int right = queries[i][1];
      int k = queries[i][2];
      int mask = prefix_masks[right + 1] ^ prefix_masks[left];
      int num_of_ones = 0;
      while (mask > 0) {
        ++num_of_ones;
        mask &= mask - 1;
      }
      result[i] = num_of_ones <= 2 * k + 1;
    }
    return result;
  }
};
