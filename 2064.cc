#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimizedMaximum(int n, vector<int>& quantities) {
    int start = 1, end = *max_element(quantities.cbegin(), quantities.cend());
    while (start <= end) {
      int mid = start + (end - start) / 2;
      long long count = 0;
      for (const auto quantity : quantities) {
        count += ceil((double)quantity / mid);
      }
      if (count <= n) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return start;
  }
};
