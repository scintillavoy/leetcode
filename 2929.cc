#include <algorithm>
using namespace std;

class Solution {
 public:
  long long distributeCandies(int n, int limit) {
    long long result = 0;
    for (int i = 0; i <= n; ++i) {
      if (i > limit) {
        break;
      }
      int num_of_candies = n - i;
      if (num_of_candies <= limit) {
        result += num_of_candies + 1;
        continue;
      }
      num_of_candies -= limit;
      result += max(0, limit - num_of_candies + 1);
    }
    return result;
  }
};
