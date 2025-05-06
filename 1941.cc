#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool areOccurrencesEqual(string s) {
    vector<int> counts(26);
    for (const auto c : s) {
      ++counts[c - 'a'];
    }
    int last_count = 0;
    for (int i = 0; i < counts.size(); ++i) {
      if (counts[i] == 0) {
        continue;
      }
      if (last_count == 0) {
        last_count = counts[i];
      } else if (last_count != counts[i]) {
        return false;
      }
    }
    return true;
  }
};
