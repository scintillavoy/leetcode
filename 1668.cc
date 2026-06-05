#include <string>
using namespace std;

class Solution {
 public:
  int maxRepeating(string sequence, string word) {
    int max_repeating = 0;
    string repeated = word;
    while (sequence.find(repeated) != string::npos) {
      ++max_repeating;
      repeated += word;
    }
    return max_repeating;
  }
};
