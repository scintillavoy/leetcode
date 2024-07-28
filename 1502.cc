#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    auto minmax = minmax_element(arr.cbegin(), arr.cend());
    int min_value = *minmax.first;
    int max_value = *minmax.second;
    if ((max_value - min_value) % (arr.size() - 1) != 0) {
      return false;
    }
    int diff = (max_value - min_value) / (arr.size() - 1);
    int i = 0;
    while (i < arr.size()) {
      if (arr[i] == min_value + diff * i) {
        ++i;
        continue;
      }
      if ((arr[i] - min_value) % diff != 0) {
        return false;
      }
      int j = (arr[i] - min_value) / diff;
      if (arr[i] == arr[j]) {
        return false;
      }
      swap(arr[i], arr[j]);
    }
    return true;
  }
};
