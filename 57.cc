#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    int left = 0;
    while (left < intervals.size()) {
      if (newInterval[0] <= intervals[left][1]) {
        break;
      }
      ++left;
    }
    int right = left;
    while (right < intervals.size()) {
      if (newInterval[1] < intervals[right][0]) {
        break;
      }
      ++right;
    }
    vector<vector<int>> result;
    for (int i = 0; i < left; ++i) {
      result.push_back(intervals[i]);
    }
    int start = newInterval[0];
    if (0 <= left && left < intervals.size()) {
      start = min(newInterval[0], intervals[left][0]);
    }
    int end = newInterval[1];
    if (0 <= right - 1 && right - 1 < intervals.size()) {
      end = max(newInterval[1], intervals[right - 1][1]);
    }
    result.push_back({start, end});
    for (int i = right; i < intervals.size(); ++i) {
      result.push_back(intervals[i]);
    }
    return result;
  }
};
