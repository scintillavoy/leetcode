#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string firstPalindrome(vector<string>& words) {
    for (const auto& word : words) {
      bool is_palindrome = true;
      for (int i = 0; i < word.size() / 2; ++i) {
        if (word[i] != word[word.size() - 1 - i]) {
          is_palindrome = false;
          break;
        }
      }
      if (is_palindrome) {
        return word;
      }
    }
    return "";
  }
};
