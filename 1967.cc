#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int numOfStrings(vector<string>& patterns, string word) {
    int result = 0;
    for (const auto& pattern : patterns) {
      if (word.find(pattern) != string::npos) {
        ++result;
      }
    }
    return result;
  }
};
