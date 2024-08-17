#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int max_score = 0;
    int left = 0;
    for (int right = 1; right < values.size(); ++right) {
      int score = values[left] + left + values[right] - right;
      max_score = max(max_score, score);
      if (values[right] - values[left] + right - left > 0) {
        left = right;
      }
    }
    return max_score;
  }
};
