#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool areSentencesSimilar(string sentence1, string sentence2) {
    vector<string> words1, words2;
    istringstream iss(sentence1);
    string word;
    while (iss >> word) {
      words1.push_back(word);
    }
    iss.clear();
    iss.str(sentence2);
    while (iss >> word) {
      words2.push_back(word);
    }
    int match_count = 0;
    for (auto it1 = words1.cbegin(), it2 = words2.cbegin();
         it1 != words1.cend() && it2 != words2.cend(); ++it1, ++it2) {
      if (*it1 != *it2) {
        break;
      }
      ++match_count;
    }
    for (auto it1 = words1.crbegin(), it2 = words2.crbegin();
         it1 != words1.crend() && it2 != words2.crend(); ++it1, ++it2) {
      if (*it1 != *it2) {
        break;
      }
      ++match_count;
    }
    return match_count >= min(words1.size(), words2.size());
  }
};
