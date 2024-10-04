#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  long long dividePlayers(vector<int>& skill) {
    vector<int> counts(*max_element(skill.cbegin(), skill.cend()) + 1);
    for (const auto s : skill) {
      ++counts[s];
    }
    long long result = 0;
    int low = 0, high = counts.size() - 1;
    while (counts[low] == 0) {
      ++low;
    }
    int target_sum = low + high;
    while (low <= high) {
      if (low + high != target_sum) {
        return -1;
      }
      result += low * high;
      --counts[low];
      --counts[high];
      while (low < counts.size() && counts[low] == 0) {
        ++low;
      }
      while (high >= 0 && counts[high] == 0) {
        --high;
      }
    }
    return result;
  }
};
