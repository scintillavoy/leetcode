#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    sort(items.begin(), items.end());
    vector<vector<int>> monotonic_items;
    monotonic_items.push_back(items[0]);
    for (int i = 1; i < items.size(); ++i) {
      if (monotonic_items.back()[0] == items[i][0]) {
        monotonic_items.pop_back();
        monotonic_items.push_back(items[i]);
      } else if (monotonic_items.back()[1] < items[i][1]) {
        monotonic_items.push_back(items[i]);
      }
    }
    vector<int> answer(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      auto it =
          upper_bound(monotonic_items.begin(), monotonic_items.end(),
                      queries[i], [](int value, const vector<int>& element) {
                        return value < element[0];
                      });
      if (it == monotonic_items.begin()) {
        answer[i] = 0;
      } else {
        answer[i] = (*(it - 1))[1];
      }
    }
    return answer;
  }
};
