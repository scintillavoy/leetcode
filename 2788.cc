#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
    vector<string> result;
    for (const auto& line : words) {
      istringstream iss(line);
      string word;
      while (getline(iss, word, separator)) {
        if (!word.empty()) {
          result.push_back(word);
        }
      }
    }
    return result;
  }
};
