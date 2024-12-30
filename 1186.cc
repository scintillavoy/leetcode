#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumSum(vector<int>& arr) {
    int max_sum_with_deletion = 0;
    int max_sum_without_deletion = arr[0];
    int max_sum = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
      max_sum_with_deletion =
          max(max_sum_with_deletion + arr[i], max_sum_without_deletion);
      max_sum_without_deletion = max(max_sum_without_deletion + arr[i], arr[i]);
      max_sum = max({max_sum, max_sum_with_deletion, max_sum_without_deletion});
    }
    return max_sum;
  }
};
