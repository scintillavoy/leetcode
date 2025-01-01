#include <algorithm>
#include <limits>
#include <string>
using namespace std;

class Solution {
 public:
  int maxScore(string s) {
    int num_of_ones = 0;
    int curr_score = 0;
    int max_score = numeric_limits<int>::min();
    for (int i = 0; i < s.size() - 1; ++i) {
      if (s[i] == '0') {
        ++curr_score;
      } else {
        --curr_score;
        ++num_of_ones;
      }
      max_score = max(max_score, curr_score);
    }
    if (s.back() == '1') {
      ++num_of_ones;
    }
    return max_score + num_of_ones;
  }
};
