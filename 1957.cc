#include <string>
using namespace std;

class Solution {
 public:
  string makeFancyString(string s) {
    string result;
    for (int i = 0; i < s.size(); ++i) {
      if (result.size() >= 2 && s[i] == *result.rbegin() &&
          *result.rbegin() == *(result.rbegin() + 1)) {
        continue;
      }
      result.push_back(s[i]);
    }
    return result;
  }
};
