#include <string>
using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int answer = 0;
    int curr_length = 0;
    for (const auto &c : s) {
      if (c == ' ') {
        curr_length = 0;
      } else {
        ++curr_length;
        answer = curr_length;
      }
    }
    return answer;
  }
};
