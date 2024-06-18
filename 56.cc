#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    result.push_back(intervals.front());
    for (int i = 1; i < intervals.size(); ++i) {
      int last = result.back()[1];
      if (intervals[i][0] > last) {
        result.push_back(intervals[i]);
        continue;
      }
      if (intervals[i][1] <= last) {
        continue;
      }
      result.back()[1] = intervals[i][1];
    }
    return result;
  }
};
