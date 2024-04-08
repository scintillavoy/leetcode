#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<pair<int, int>> times;
    for (const auto& interval : intervals) {
      times.push_back({interval[0], 1});
      times.push_back({interval[1], -1});
    }
    sort(times.begin(), times.end());
    int max_count = 0;
    int count = 0;
    for (const auto& time : times) {
      count += time.second;
      max_count = max(max_count, count);
    }
    return max_count;
  }
};
