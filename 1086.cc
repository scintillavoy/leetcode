#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> highFive(vector<vector<int>>& items) {
    vector<vector<int>> result;
    sort(items.begin(), items.end());
    for (int i = 4; i < items.size(); ++i) {
      if (i + 1 == items.size() || items[i][0] != items[i + 1][0]) {
        int sum = 0;
        for (int j = i - 4; j <= i; ++j) {
          sum += items[j][1];
        }
        result.push_back({items[i][0], sum / 5});
      }
    }
    return result;
  }
};
