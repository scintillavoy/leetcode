#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  char findTheDifference(string s, string t) {
    vector<int> counts(26);
    for (const auto c : s) {
      ++counts[c - 'a'];
    }
    for (const auto c : t) {
      --counts[c - 'a'];
    }
    for (int i = 0; i < counts.size(); ++i) {
      if (counts[i] != 0) {
        return i + 'a';
      }
    }
    return -1;
  }
};
