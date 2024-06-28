#include <algorithm>
#include <string>
using namespace std;

class Solution {
 public:
  int maxVowels(string s, int k) {
    int count = 0;
    for (int i = 0; i < k; ++i) {
      if (is_vowel(s[i])) {
        ++count;
      }
    }
    int max_count = count;
    for (int i = k; i < s.size(); ++i) {
      if (is_vowel(s[i - k])) {
        --count;
      }
      if (is_vowel(s[i])) {
        ++count;
      }
      max_count = max(max_count, count);
    }
    return max_count;
  }

 private:
  bool is_vowel(char c) {
    switch (c) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        return true;
      default:
        return false;
    }
  }
};
