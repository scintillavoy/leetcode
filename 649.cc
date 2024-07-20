#include <queue>
#include <string>
using namespace std;

class Solution {
 public:
  string predictPartyVictory(string senate) {
    int r_count = 0, d_count = 0;
    queue<char> q;
    for (const auto c : senate) {
      if (c == 'R') {
        ++r_count;
      } else {
        ++d_count;
      }
      q.push(c);
    }
    int r_ban = 0, d_ban = 0;
    while (!q.empty()) {
      if (r_count == 0) {
        return "Dire";
      }
      if (d_count == 0) {
        return "Radiant";
      }
      int curr = q.front();
      q.pop();
      if (curr == 'R') {
        if (r_ban > 0) {
          --r_ban;
        } else {
          ++d_ban;
          --d_count;
          q.push(curr);
        }
      } else {
        if (d_ban > 0) {
          --d_ban;
        } else {
          ++r_ban;
          --r_count;
          q.push(curr);
        }
      }
    }
    return "";
  }
};
