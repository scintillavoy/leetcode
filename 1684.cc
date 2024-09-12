#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    vector<bool> allowed_vec(26);
    for (const auto c : allowed) {
      allowed_vec[c - 'a'] = true;
    }
    int count = 0;
    for (const auto& word : words) {
      bool is_consistent = true;
      for (const auto c : word) {
        if (!allowed_vec[c - 'a']) {
          is_consistent = false;
          break;
        }
      }
      if (is_consistent) {
        ++count;
      }
    }
    return count;
  }
};
