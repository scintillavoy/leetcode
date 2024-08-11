#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());
    int score = 0;
    int max_score = 0;
    int left = 0, right = tokens.size() - 1;
    while (left <= right) {
      while (left <= right && tokens[left] <= power) {
        power -= tokens[left];
        ++score;
        ++left;
      }
      if (score == 0) {
        break;
      }
      max_score = max(max_score, score);
      power += tokens[right];
      --score;
      --right;
    }
    return max_score;
  }
};
