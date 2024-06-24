#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  long long repairCars(vector<int>& ranks, int cars) {
    int avg = ceil((double)cars / ranks.size());
    auto [min, max] = minmax_element(ranks.cbegin(), ranks.cend());
    long long start = (long long)*min * avg * avg;
    long long end = (long long)*max * avg * avg;
    while (start <= end) {
      long long mid = start + (end - start) / 2;
      long long count = 0;
      for (const auto rank : ranks) {
        count += sqrt(mid / rank);
      }
      if (count >= cars) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return start;
  }
};
