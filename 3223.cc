#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumLength(string s) {
    vector<int> counts(26);
    for (const auto c : s) {
      ++counts[c - 'a'];
    }
    int min_length = 0;
    for (const auto count : counts) {
      if (count == 0) {
        continue;
      }
      min_length += count % 2 == 0 ? 2 : 1;
    }
    return min_length;
  }
};
