#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int minSteps(string s, string t) {
    vector<int> counts(26);
    for (const auto c : t) {
      ++counts[c - 'a'];
    }
    for (const auto c : s) {
      --counts[c - 'a'];
    }
    int min_steps = 0;
    for (const auto count : counts) {
      if (count > 0) {
        min_steps += count;
      }
    }
    return min_steps;
  }
};
