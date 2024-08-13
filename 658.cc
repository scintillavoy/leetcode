#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int right = lower_bound(arr.cbegin(), arr.cend(), x) - arr.cbegin();
    int left = right - 1;
    int count = 0;
    while (count < k && left >= 0 && right < arr.size()) {
      if (abs(x - arr[left]) <= abs(x - arr[right])) {
        --left;
      } else {
        ++right;
      }
      ++count;
    }
    if (count < k) {
      if (left >= 0) {
        left -= k - count;
      } else {
        right += k - count;
      }
    }
    vector<int> result;
    for (int i = left + 1; i < right; ++i) {
      result.push_back(arr[i]);
    }
    return result;
  }
};
