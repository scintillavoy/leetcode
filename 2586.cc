#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int vowelStrings(vector<string>& words, int left, int right) {
    int count = 0;
    for (int i = left; i <= right; ++i) {
      if (is_vowel(words[i].front()) && is_vowel(words[i].back())) {
        ++count;
      }
    }
    return count;
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
    }
    return false;
  }
};
