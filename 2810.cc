#include <deque>
#include <string>
using namespace std;

class Solution {
 public:
  string finalString(string s) {
    deque<char> typed_string;
    bool reversed = false;
    for (const auto c : s) {
      if (c == 'i') {
        reversed = !reversed;
        continue;
      }
      if (reversed) {
        typed_string.push_front(c);
      } else {
        typed_string.push_back(c);
      }
    }
    if (reversed) {
      return string(typed_string.rbegin(), typed_string.rend());
    }
    return string(typed_string.begin(), typed_string.end());
  }
};
