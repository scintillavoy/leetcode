#include <string>
#include <utility>
using namespace std;

class Solution {
 public:
  string reverseVowels(string s) {
    int start = 0, end = s.size() - 1;
    while (true) {
      while (start < s.size() && !is_vowel(s[start])) {
        ++start;
      }
      while (end >= 0 && !is_vowel(s[end])) {
        --end;
      }
      if (start >= end) {
        break;
      }
      swap(s[start], s[end]);
      ++start;
      --end;
    }
    return s;
  }

 private:
  bool is_vowel(char c) {
    switch (c) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        return true;
      default:
        return false;
    }
  }
};
