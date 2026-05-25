#include <queue>
#include <string>
using namespace std;

class Solution {
 public:
  bool canReach(string s, int minJump, int maxJump) {
    queue<int> q;
    q.push(0);
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == '1') {
        continue;
      }
      int low = i - maxJump;
      int high = i - minJump;
      while (!q.empty() && q.front() < low) {
        q.pop();
      }
      if (!q.empty() && q.front() <= high) {
        q.push(i);
      }
    }
    return q.back() == s.size() - 1;
  }
};
