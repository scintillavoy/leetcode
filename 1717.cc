#include <string>
using namespace std;

class Solution {
 public:
  int maximumGain(string s, int x, int y) {
    int result = 0;
    if (x < y) {
      return remove_substring(s, "ba") * y + remove_substring(s, "ab") * x;
    }
    return remove_substring(s, "ab") * x + remove_substring(s, "ba") * y;
  }

 private:
  int remove_substring(string& s, string substr) {
    int count = 0;
    string result;
    for (const auto c : s) {
      result += c;
      if (result.size() >= substr.size() &&
          (result.substr(result.size() - substr.size()) == substr)) {
        ++count;
        for (int i = 0; i < substr.size(); ++i) {
          result.pop_back();
        }
      }
    }
    s = result;
    return count;
  }
};
