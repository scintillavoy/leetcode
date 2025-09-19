#include <string>
using namespace std;

class Solution {
 public:
  int countAsterisks(string s) {
    int num_of_asterisks = 0;
    int index = 0;
    while (index < s.size()) {
      while (index < s.size() && s[index] != '|') {
        if (s[index] == '*') {
          ++num_of_asterisks;
        }
        ++index;
      }
      ++index;
      while (index < s.size() && s[index] != '|') {
        ++index;
      }
      ++index;
    }
    return num_of_asterisks;
  }
};
