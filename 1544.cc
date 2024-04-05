#include <cctype>
#include <string>
using namespace std;

class Solution {
 public:
  string makeGood(string s) {
    string answer;
    answer.push_back(s[0]);
    for (int i = 1; i < s.size(); ++i) {
      if (!answer.empty() && answer.back() != s[i] &&
          tolower(answer.back()) == tolower(s[i])) {
        answer.pop_back();
      } else {
        answer.push_back(s[i]);
      }
    }
    return answer;
  }
};
