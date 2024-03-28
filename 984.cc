#include <string>
using namespace std;

class Solution {
 public:
  string strWithout3a3b(int a, int b) {
    string answer;
    while (a != 0 && b != 0) {
      int index = answer.size();
      if (a >= b) {
        if (index >= 2 && answer[index - 1] == 'a' &&
            answer[index - 2] == 'a') {
          answer.push_back('b');
          --b;
        } else {
          answer.push_back('a');
          --a;
        }
      } else if (a < b) {
        if (index >= 2 && answer[index - 1] == 'b' &&
            answer[index - 2] == 'b') {
          answer.push_back('a');
          --a;
        } else {
          answer.push_back('b');
          --b;
        }
      }
    }
    while (a != 0) {
      answer.push_back('a');
      --a;
    }
    while (b != 0) {
      answer.push_back('b');
      --b;
    }
    return answer;
  }
};
