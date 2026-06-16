#include <deque>
#include <string>
using namespace std;

class Solution {
 public:
  string processStr(string s) {
    deque<char> dq;
    bool reversed = false;
    for (const auto ch : s) {
      if (ch == '*') {
        // Remove
        if (dq.empty()) {
          continue;
        }
        if (reversed) {
          dq.pop_front();
        } else {
          dq.pop_back();
        }
      } else if (ch == '#') {
        // Duplicate
        int size = dq.size();
        for (int i = 0; i < size; ++i) {
          dq.push_back(dq[i]);
        }
      } else if (ch == '%') {
        // Reverse
        reversed = !reversed;
      } else {
        // Append
        if (reversed) {
          dq.push_front(ch);
        } else {
          dq.push_back(ch);
        }
      }
    }
    return reversed ? string(dq.rbegin(), dq.rend())
                    : string(dq.begin(), dq.end());
  }
};
