#include <string>
using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    int answer = 0;
    s.push_back('-');
    for (int i = 0; i < s.size() - 1; ++i) {
      if ((s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ||
          (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
          (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))) {
        answer += charToInt(s[i + 1]) - charToInt(s[i]);
        ++i;
        continue;
      }
      answer += charToInt(s[i]);
    }
    return answer;
  }

 private:
  int charToInt(char c) {
    switch (c) {
      case 'I':
        return 1;
      case 'V':
        return 5;
      case 'X':
        return 10;
      case 'L':
        return 50;
      case 'C':
        return 100;
      case 'D':
        return 500;
      case 'M':
        return 1000;
    }
    return -1;
  }
};
