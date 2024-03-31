#include <string>
using namespace std;

class Solution {
 public:
  string mergeAlternately(string word1, string word2) {
    string answer;
    auto it1 = word1.cbegin();
    auto it2 = word2.cbegin();
    while (it1 != word1.cend() && it2 != word2.cend()) {
      answer += *it1;
      answer += *it2;
      ++it1;
      ++it2;
    }
    while (it1 != word1.cend()) {
      answer += *it1;
      ++it1;
    }
    while (it2 != word2.cend()) {
      answer += *it2;
      ++it2;
    }
    return answer;
  }
};
