#include <limits>
#include <string>
using namespace std;

class Solution {
 public:
  int maxScore(string s) {
    int count = 0;
    int min_count = numeric_limits<int>::max();
    int min_idx = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '0')
        --count;
      else
        ++count;
      if (count < min_count) {
        min_count = count;
        min_idx = i;
      }
    }
    if (min_idx == s.size() - 1) {
      --min_idx;
    }
    int maxScore = 0;
    for (int i = 0; i <= min_idx; ++i) {
      if (s[i] == '0') ++maxScore;
    }
    for (int i = min_idx + 1; i < s.size(); ++i) {
      if (s[i] == '1') ++maxScore;
    }
    return maxScore;
  }
};

int main() { return 0; }
