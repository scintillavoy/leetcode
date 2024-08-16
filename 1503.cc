#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int result = 0;
    if (!left.empty()) {
      result = max(result, *max_element(left.cbegin(), left.cend()));
    }
    if (!right.empty()) {
      result = max(result, n - *min_element(right.cbegin(), right.cend()));
    }
    return result;
  }
};
