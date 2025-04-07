#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string sortSentence(string s) {
    vector<string> words;
    istringstream iss(s);
    string word;
    while (iss >> word) {
      words.push_back(word);
    }
    sort(words.begin(), words.end(),
         [](const string &a, const string &b) { return a.back() < b.back(); });
    string result;
    for (const auto &word : words) {
      result += word;
      result.pop_back();
      result += ' ';
    }
    result.pop_back();
    return result;
  }
};
