#include <algorithm>
#include <functional>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumPushes(string word) {
    vector<int> counts(26);
    for (const auto c : word) {
      ++counts[c - 'a'];
    }
    sort(counts.begin(), counts.end(), greater<int>());
    int min_num = 0;
    for (int i = 0; i < counts.size(); ++i) {
      if (counts[i] == 0) {
        break;
      }
      min_num += (i / 8 + 1) * counts[i];
    }
    return min_num;
  }
};
