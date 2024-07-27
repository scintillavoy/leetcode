#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int compress(vector<char>& chars) {
    int count = 1;
    int length = 1;
    for (int i = 1; i < chars.size(); ++i) {
      if (chars[i - 1] == chars[i]) {
        ++count;
      } else {
        if (count > 1) {
          for (const auto c : to_string(count)) {
            chars[length] = c;
            ++length;
          }
        }
        count = 1;
        chars[length] = chars[i];
        ++length;
      }
    }
    if (count > 1) {
      for (const auto c : to_string(count)) {
        chars[length] = c;
        ++length;
      }
    }
    return length;
  }
};
