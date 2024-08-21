#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int max_value = *max_element(citations.cbegin(), citations.cend());
    vector<int> counts(max_value + 1);
    for (const auto citation : citations) {
      ++counts[citation];
    }
    int sum = 0;
    for (int i = counts.size() - 1; i >= 0; --i) {
      sum += counts[i];
      if (sum >= i) {
        return i;
      }
    }
    return -1;
  }
};
