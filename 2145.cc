#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int numberOfArrays(vector<int>& differences, int lower, int upper) {
    long long max_value = 0;
    long long min_value = 0;
    long long current_value = 0;
    for (const auto difference : differences) {
      current_value += difference;
      max_value = max(max_value, current_value);
      min_value = min(min_value, current_value);
    }
    return max(0LL, upper - lower - (max_value - min_value) + 1);
  }
};
