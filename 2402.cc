#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    vector<int> meeting_count(n);
    priority_queue<int, vector<int>, greater<int>> unused_rooms;
    for (int i = 0; i < n; ++i) {
      unused_rooms.push(i);
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        used_rooms;
    sort(meetings.begin(), meetings.end());

    for (int i = 0; i < meetings.size(); ++i) {
      int start = meetings[i][0], end = meetings[i][1];
      while (!used_rooms.empty() && used_rooms.top().first <= start) {
        unused_rooms.push(used_rooms.top().second);
        used_rooms.pop();
      }
      long long delay = 0;
      if (unused_rooms.empty()) {
        delay = used_rooms.top().first - start;
        unused_rooms.push(used_rooms.top().second);
        used_rooms.pop();
      }
      int room = unused_rooms.top();
      unused_rooms.pop();
      used_rooms.push({end + delay, room});
      ++meeting_count[room];
    }
    return max_element(meeting_count.cbegin(), meeting_count.cend()) -
           meeting_count.cbegin();
  }
};
