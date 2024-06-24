#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumCandies(vector<int>& candies, long long k) {
    int start = 1, end = *max_element(candies.cbegin(), candies.cend());
    while (start <= end) {
      int mid = start + (end - start) / 2;
      long long count = 0;
      for (const auto candy : candies) {
        count += candy / mid;
      }
      if (count < k) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return start - 1;
  }
};
