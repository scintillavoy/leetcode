#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    int sum = 0;
    for (int i = 0; i < k; ++i) {
      sum += cardPoints[i];
    }
    int max_sum = sum;
    for (int i = 0; i < k; ++i) {
      sum = sum - cardPoints[k - 1 - i] + cardPoints[cardPoints.size() - 1 - i];
      max_sum = max(max_sum, sum);
    }
    return max_sum;
  }
};
