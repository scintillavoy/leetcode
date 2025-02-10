#include <cctype>
#include <string>
using namespace std;

class Solution {
 public:
  string clearDigits(string s) {
    string result;
    for (const auto c : s) {
      if (isdigit(c)) {
        result.pop_back();
      } else {
        result.push_back(c);
      }
    }
    return result;
  }
};
