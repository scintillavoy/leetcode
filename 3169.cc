#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int countDays(int days, vector<vector<int>>& meetings) {
    int count = 0;
    int last_meeting_day = 0;
    sort(meetings.begin(), meetings.end());
    for (const auto& meeting : meetings) {
      count += max(0, meeting[0] - 1 - last_meeting_day);
      last_meeting_day = max(last_meeting_day, meeting[1]);
    }
    count += days - last_meeting_day;
    return count;
  }
};
