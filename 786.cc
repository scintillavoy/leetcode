#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    int n = arr.size();
    double left = 0.0, right = 1.0;
    while (left < right) {
      double mid = (left + right) / 2;
      double max_fraction = 0.0;
      int count = 0;
      int numerator_idx, denominator_idx;
      int j = 1;

      // Count fractions smaller than mid.
      for (int i = 0; i < n - 1; ++i) {
        while (j < n && (double)arr[i] / arr[j] >= mid) {
          ++j;
        }
        count += n - j;
        if (j == n) {
          break;
        }
        double fraction = (double)arr[i] / arr[j];
        if (max_fraction < fraction) {
          max_fraction = fraction;
          numerator_idx = i;
          denominator_idx = j;
        }
      }

      if (count == k) {
        return {arr[numerator_idx], arr[denominator_idx]};
      } else if (count > k) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return {};
  }
};
