#include <cctype>
#include <string>
using namespace std;

class Solution {
 public:
  string maskPII(string s) {
    string masked;
    if (isalpha(s[0])) {
      // Email address
      int i = 0;
      while (s[i] != '@') {
        ++i;
      }
      masked += tolower(s[0]);
      masked += "*****";
      masked += tolower(s[i - 1]);
      while (i < s.size()) {
        masked += tolower(s[i]);
        ++i;
      }
    } else {
      // Phone number
      string digits;
      for (const auto c : s) {
        if (isdigit(c)) {
          digits += c;
        }
      }
      if (digits.size() > 10) {
        masked += '+';
        for (int i = 0; i + 10 < digits.size(); ++i) {
          masked += '*';
        }
        masked += '-';
      }
      masked += "***-***-";
      for (int i = 4; i > 0; --i) {
        masked += digits[digits.size() - i];
      }
    }
    return masked;
  }
};
