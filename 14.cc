#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string prefix;
    for (int index = 0; index < strs[0].size(); ++index) {
      char curr = strs[0][index];
      for (int i = 1; i < strs.size(); ++i) {
        if (index >= strs[i].size() || strs[i][index] != curr) {
          return prefix;
        }
      }
      prefix.push_back(curr);
    }
    return prefix;
  }
};
