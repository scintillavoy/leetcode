#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int mostWordsFound(vector<string>& sentences) {
    int max_num = 0;
    for (const auto& sentence : sentences) {
      int num_of_words = 1;
      for (const auto c : sentence) {
        if (c == ' ') {
          ++num_of_words;
        }
      }
      max_num = max(max_num, num_of_words);
    }
    return max_num;
  }
};
