#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    vector<string> answer(n);
    for (int i = 3; i <= n; i += 3) {
      answer[i - 1] += "Fizz";
    }
    for (int i = 5; i <= n; i += 5) {
      answer[i - 1] += "Buzz";
    }
    for (int i = 1; i <= n; ++i) {
      if (answer[i - 1].empty()) {
        answer[i - 1] = to_string(i);
      }
    }
    return answer;
  }
};
