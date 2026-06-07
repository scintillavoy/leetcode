#include <vector>
using namespace std;

class Solution {
 public:
  int kConcatenationMaxSum(vector<int>& arr, int k) {
    int n = arr.size();
    if (k > 1) {
      for (int i = 0; i < n; ++i) {
        arr.push_back(arr[i]);
      }
    }
    int max_left = 0;
    int max_right = -1;
    int max_sum = 0;
    int left = 0;
    int sum = 0;
    for (int right = 0; right < arr.size(); ++right) {
      sum += arr[right];
      if (sum <= 0) {
        left = right + 1;
        sum = 0;
      }
      if (max_sum < sum) {
        max_sum = sum;
        max_left = left;
        max_right = right;
      }
    }
    if (max_right < n) {
      return max_sum;
    }
    int total_sum = 0;
    for (int i = 0; i < n; ++i) {
      total_sum += arr[i];
    }
    if (total_sum <= 0) {
      return max_sum;
    }
    return ((long long)total_sum * (k - 2) + max_sum) % 1'000'000'007;
  }
};
