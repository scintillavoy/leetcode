#include <algorithm>
#include <string>
using namespace std;

class Solution {
 public:
  int maxDepth(string s) {
    int answer = 0;
    int curr = 0;
    for (const auto &c : s) {
      if (c == '(') {
        ++curr;
        answer = max(answer, curr);
      } else if (c == ')') {
        --curr;
      }
    }
    return answer;
  }
};
