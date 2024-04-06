#include <string>
using namespace std;

class Solution {
 public:
  int countTime(string time) {
    int answer = 1;
    if (time[3] == '?') {
      answer *= 6;
    }
    if (time[4] == '?') {
      answer *= 10;
    }
    if (time[0] == '?' && time[1] == '?') {
      answer *= 24;
    } else if (time[0] == '?') {
      if (time[1] <= '3') {
        answer *= 3;
      } else {
        answer *= 2;
      }
    } else if (time[1] == '?') {
      if (time[0] == '2') {
        answer *= 4;
      } else {
        answer *= 10;
      }
    }
    return answer;
  }
};
