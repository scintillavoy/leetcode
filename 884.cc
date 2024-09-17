#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> uncommonFromSentences(string s1, string s2) {
    istringstream iss(s1);
    string word;
    unordered_map<string, int> counts;
    while (iss >> word) {
      ++counts[word];
    }
    iss.clear();
    iss.str(s2);
    while (iss >> word) {
      ++counts[word];
    }
    vector<string> result;
    for (const auto &[word, count] : counts) {
      if (count == 1) {
        result.push_back(word);
      }
    }
    return result;
  }
};
