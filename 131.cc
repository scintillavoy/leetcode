#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    for (int i = 0; i < (1 << (s.size() - 1)); ++i) {
      vector<string> partition;
      string substr;
      bool valid = true;
      for (int j = 0; j < s.size(); ++j) {
        substr.push_back(s[j]);
        if ((i & (1 << j)) != 0 || j == s.size() - 1) {
          if (!is_palindrome(substr)) {
            valid = false;
            break;
          }
          partition.push_back(substr);
          substr.clear();
        }
      }
      if (valid) {
        result.push_back(partition);
      }
    }
    return result;
  }

 private:
  bool is_palindrome(const string &s) {
    for (int i = 0; i < s.size() / 2; ++i) {
      if (s[i] != s[s.size() - 1 - i]) {
        return false;
      }
    }
    return true;
  }
};
