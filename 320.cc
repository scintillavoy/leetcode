#include <cctype>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> generateAbbreviations(string word) {
    vector<string> result;
    string str;
    backtrack(str, 0, result, word);
    return result;
  }

 private:
  void backtrack(string &str, int start_index, vector<string> &result,
                 const string &word) {
    if (start_index >= word.size()) {
      result.push_back(str);
      return;
    }
    str.push_back(word[start_index]);
    backtrack(str, start_index + 1, result, word);
    str.pop_back();
    for (int i = start_index; i < word.size(); ++i) {
      str += to_string(i - start_index + 1);
      if (i + 1 < word.size()) {
        str.push_back(word[i + 1]);
      }
      backtrack(str, i + 2, result, word);
      if (i + 1 < word.size()) {
        str.pop_back();
      }
      while (!str.empty() && isdigit(str.back())) {
        str.pop_back();
      }
    }
  }
};
