#include <vector>
using namespace std;

class Solution {
 public:
  int numTeams(vector<int>& rating) {
    int result = 0;
    for (int i = 1; i < rating.size() - 1; ++i) {
      int less = 0;
      for (int j = 0; j < i; ++j) {
        if (rating[j] < rating[i]) {
          ++less;
        }
      }
      int greater = 0;
      for (int j = i + 1; j < rating.size(); ++j) {
        if (rating[j] > rating[i]) {
          ++greater;
        }
      }
      result += less * greater + (i - less) * (rating.size() - 1 - i - greater);
    }
    return result;
  }
};
