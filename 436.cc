#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findRightInterval(vector<vector<int>>& intervals) {
    vector<tuple<int, int, int>> intervals_with_index;
    for (int i = 0; i < intervals.size(); ++i) {
      intervals_with_index.push_back({intervals[i][0], intervals[i][1], i});
    }
    sort(intervals_with_index.begin(), intervals_with_index.end());
    vector<int> result;
    for (const auto& interval : intervals) {
      int low = 0;
      int high = intervals_with_index.size() - 1;
      while (low <= high) {
        int mid = low + (high - low) / 2;
        if (interval[1] <= get<0>(intervals_with_index[mid])) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      result.push_back(low == intervals_with_index.size()
                           ? -1
                           : get<2>(intervals_with_index[low]));
    }
    return result;
  }
};
