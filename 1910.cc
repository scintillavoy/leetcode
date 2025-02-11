#include <string>
using namespace std;

class Solution {
 public:
  string removeOccurrences(string s, string part) {
    string result;
    for (int i = 0; i < s.size(); ++i) {
      result.push_back(s[i]);
      while (result.ends_with(part)) {
        for (int j = 0; j < part.size(); ++j) {
          result.pop_back();
        }
      }
    }
    return result;
  }
};
