#include <sstream>
#include <string>
using namespace std;

class Solution {
 public:
  bool isCircularSentence(string sentence) {
    istringstream iss(sentence);
    string prev_word;
    iss >> prev_word;
    string word;
    while (iss >> word) {
      if (prev_word.back() != word.front()) {
        return false;
      }
      prev_word = word;
    }
    return sentence.front() == sentence.back();
  }
};
