#include <cctype>
#include <string>
using namespace std;

class Solution {
 public:
  bool isValid(string word) {
    if (word.size() < 3) {
      return false;
    }
    bool contains_vowel = false;
    bool contains_consonant = false;
    for (const auto c : word) {
      if (isdigit(c)) {
        continue;
      }
      if (isalpha(c)) {
        if (is_vowel(c)) {
          contains_vowel = true;
        } else {
          contains_consonant = true;
        }
        continue;
      }
      return false;
    }
    return contains_vowel && contains_consonant;
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
    }
    return false;
  }
};
