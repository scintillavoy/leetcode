#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  string replaceWords(vector<string>& dictionary, string sentence) {
    unordered_set<string> dict_set(dictionary.cbegin(), dictionary.cend());
    istringstream iss(sentence);
    string result, word;
    while (iss >> word) {
      string prefix;
      for (int i = 0; i < word.size(); ++i) {
        prefix += word[i];
        if (dict_set.count(prefix) != 0 || i + 1 == word.size()) {
          result += prefix;
          break;
        }
      }
      result += ' ';
    }
    result.pop_back();
    return result;
  }
};
