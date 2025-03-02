#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minSwaps(vector<int>& data) {
    int num_of_ones = 0;
    for (const auto num : data) {
      if (num == 1) {
        ++num_of_ones;
      }
    }
    int min_swaps = num_of_ones;
    int num_of_zeros = 0;
    int left = 0;
    for (int right = 0; right < data.size(); ++right) {
      if (data[right] == 0) {
        ++num_of_zeros;
      }
      if (right - left + 1 > num_of_ones) {
        if (data[left] == 0) {
          --num_of_zeros;
        }
        ++left;
      }
      if (right - left + 1 == num_of_ones) {
        min_swaps = min(min_swaps, num_of_zeros);
      }
    }
    return min_swaps;
  }
};
