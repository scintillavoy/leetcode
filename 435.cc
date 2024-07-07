#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int result = 0;
    int last = intervals.front()[1];
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] < last) {
        ++result;
        last = min(last, intervals[i][1]);
      } else {
        last = intervals[i][1];
      }
    }
    return result;
  }
};
