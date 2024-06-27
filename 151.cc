#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    istringstream iss(s);
    string word;
    vector<string> words;
    while (iss >> word) {
      words.push_back(word);
    }
    string result;
    for (auto it = words.crbegin(); it != words.crend(); ++it) {
      result += *it;
      result += ' ';
    }
    result.pop_back();
    return result;
  }
};
