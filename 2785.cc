#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  string sortVowels(string s) {
    unordered_map<char, int> count;
    for (const auto &c : s) {
      if (is_vowel(c)) {
        ++count[c];
      }
    }
    string sorted_vowels("AEIOUaeiou");
    int vowel_index = 0;
    for (auto &c : s) {
      if (is_vowel(c)) {
        while (count[sorted_vowels[vowel_index]] == 0) {
          ++vowel_index;
        }
        c = sorted_vowels[vowel_index];
        --count[sorted_vowels[vowel_index]];
      }
    }
    return s;
  }

 private:
  bool is_vowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
           c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};
