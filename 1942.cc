#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int smallestChair(vector<vector<int>>& times, int targetFriend) {
    vector<Event> events;
    for (int i = 0; i < times.size(); ++i) {
      events.push_back({times[i][0], true, i});
      events.push_back({times[i][1], false, i});
    }
    sort(events.begin(), events.end());
    set<int> occupied_chairs, unoccupied_chairs;
    unordered_map<int, int> friend_to_chair;
    for (const auto& event : events) {
      if (event.is_arriving) {
        int chair = 0;
        if (!unoccupied_chairs.empty()) {
          chair = *unoccupied_chairs.begin();
          unoccupied_chairs.erase(chair);
        } else if (!occupied_chairs.empty()) {
          chair = *occupied_chairs.rbegin() + 1;
        }
        occupied_chairs.insert(chair);
        friend_to_chair[event.friend_id] = chair;
        if (event.friend_id == targetFriend) {
          return chair;
        }
      } else {
        int chair = friend_to_chair[event.friend_id];
        friend_to_chair.erase(event.friend_id);
        occupied_chairs.erase(chair);
        unoccupied_chairs.insert(chair);
      }
    }
    return -1;
  }

 private:
  struct Event {
    int time;
    bool is_arriving;
    int friend_id;

    bool operator<(const Event& other) const {
      if (time != other.time) {
        return time < other.time;
      }
      return is_arriving < other.is_arriving;
    }
  };
};
