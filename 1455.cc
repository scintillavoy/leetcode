#include <sstream>
#include <string>
using namespace std;

class Solution {
 public:
  int isPrefixOfWord(string sentence, string searchWord) {
    istringstream iss(sentence);
    int result = 0;
    string word;
    while (iss >> word) {
      ++result;
      if (word.size() < searchWord.size()) {
        continue;
      }
      bool valid = true;
      for (int i = 0; i < searchWord.size(); ++i) {
        if (word[i] != searchWord[i]) {
          valid = false;
          break;
        }
      }
      if (valid) {
        return result;
      }
    }
    return -1;
  }
};
