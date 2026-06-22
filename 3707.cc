#include <string>
using namespace std;

class Solution {
 public:
  bool scoreBalance(string s) {
    int left_score = 0;
    int right_score = 0;
    for (int i = 0; i < s.size(); ++i) {
      right_score += s[i] - 'a' + 1;
    }
    for (int i = 0; i + 1 < s.size(); ++i) {
      int curr_score = s[i] - 'a' + 1;
      left_score += curr_score;
      right_score -= curr_score;
      if (left_score == right_score) {
        return true;
      }
    }
    return false;
  }
};
