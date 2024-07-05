#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool> visited(rooms.size());
    queue<int> q;
    visited[0] = true;
    q.push(0);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (const auto room : rooms[curr]) {
        if (!visited[room]) {
          visited[room] = true;
          q.push(room);
        }
      }
    }
    for (const auto v : visited) {
      if (!v) {
        return false;
      }
    }
    return true;
  }
};
