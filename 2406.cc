#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  int minGroups(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    map<int, int> groups;
    for (const auto& interval : intervals) {
      auto it = groups.lower_bound(interval[0]);
      if (it != groups.begin()) {
        --it;
        --(it->second);
        if (it->second == 0) {
          groups.erase(it);
        }
      }
      ++groups[interval[1]];
    }
    int count = 0;
    for (const auto [k, v] : groups) {
      count += v;
    }
    return count;
  }
};
