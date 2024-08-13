#include <cctype>
#include <string>
using namespace std;

class Solution {
 public:
  bool detectCapitalUse(string word) {
    int num_of_uppercase = 0;
    int num_of_lowercase = 0;
    for (const auto c : word) {
      if (isupper(c)) {
        ++num_of_uppercase;
      } else if (islower(c)) {
        ++num_of_lowercase;
      }
    }
    return (num_of_uppercase == word.size() ||
            num_of_lowercase == word.size() ||
            (num_of_uppercase == 1 && isupper(word.front())));
  }
};
