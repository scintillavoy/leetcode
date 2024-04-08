#include <string>
using namespace std;

class Solution {
 public:
  string removeVowels(string s) {
    string answer;
    for (const char &c : s) {
      switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
          continue;
      }
      answer.push_back(c);
    }
    return answer;
  }
};
