#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int numberOfSubstrings(string s) {
    int num_of_substrings = 0;
    unordered_map<char, int> counts;
    int start = 0;
    for (int end = 0; end < s.size(); ++end) {
      ++counts[s[end]];
      while (counts.size() == 3) {
        num_of_substrings += s.size() - end;
        --counts[s[start]];
        if (counts[s[start]] == 0) {
          counts.erase(s[start]);
        }
        ++start;
      }
    }
    return num_of_substrings;
  }
};
